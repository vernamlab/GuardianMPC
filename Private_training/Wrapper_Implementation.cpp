#include "TinyLEGO-master/src/tiny-mains/tiny-const-main.cpp"
#include "TinyLEGO-master/src/tiny-mains/tiny-eval-main.cpp"

void ProcessDataset(const float* dataset, size_t dim1, size_t dim2, size_t dim3, float** weights, size_t weights_dim1, size_t weights_dim2, const TinyParams& params) {
    // Step 1: Prepare dataset input for tiny-const-main
    // Convert 3D dataset to appropriate binary format for tiny-const-main
    std::string input_file = "dataset_input.bin";
    FILE* file = fopen(input_file.c_str(), "wb");
    if (!file) {
        std::cerr << "Error opening file for writing: " << input_file << std::endl;
        return;
    }
    fwrite(dataset, sizeof(float), dim1 * dim2 * dim3, file);
    fclose(file);

    // Run tiny-const-main with the prepared dataset
    std::vector<std::string> const_args = {
        "Tinyconst",
        "-n", std::to_string(params.num_iters),
        "-c", params.circuit_name,
        "-e", std::to_string(params.num_execs[0]) + "," +
              std::to_string(params.num_execs[1]) + "," +
              std::to_string(params.num_execs[2]),
        "-o", std::to_string(params.optimize_online),
        "-ip", params.ip_address,
        "-p", std::to_string(params.port),
        "-f", input_file
    };

    std::vector<const char*> const_c_args;
    for (const auto& arg : const_args) {
        const_c_args.push_back(arg.c_str());
    }
    main(static_cast<int>(const_c_args.size()), const_c_args.data());

    // Step 2: Prepare the output of tiny-const-main for tiny-eval-main
    std::string eval_output_file = "eval_output.bin";

    // Assuming tiny-const-main produces some intermediate output required by tiny-eval-main
    std::vector<std::string> eval_args = {
        "Tinyeval",
        "-n", std::to_string(params.num_iters),
        "-c", params.circuit_name,
        "-e", std::to_string(params.num_execs[0]) + "," +
              std::to_string(params.num_execs[1]) + "," +
              std::to_string(params.num_execs[2]),
        "-o", std::to_string(params.optimize_online),
        "-ip", params.ip_address,
        "-p", std::to_string(params.port),
        "-f", eval_output_file
    };

    std::vector<const char*> eval_c_args;
    for (const auto& arg : eval_args) {
        eval_c_args.push_back(arg.c_str());
    }
    main(static_cast<int>(eval_c_args.size()), eval_c_args.data());

    // Step 3: Read the output of tiny-eval-main and store it in the weights array
    file = fopen(eval_output_file.c_str(), "rb");
    if (!file) {
        std::cerr << "Error opening file for reading: " << eval_output_file << std::endl;
        return;
    }
    size_t total_weights = weights_dim1 * weights_dim2;
    fread(&weights[0][0], sizeof(float), total_weights, file);
    fclose(file);
}
