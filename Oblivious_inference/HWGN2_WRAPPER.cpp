#include "HWGN2_WRAPPER.h"
#include "../Private_training/TinyLEGO-master/src/tiny-mains/tiny-const-main.cpp"
#include "../Private_training/TinyLEGO-master/src/tiny-mains/tiny-eval-main.cpp"
#include "HWGN2-main/TinyGarble/garbled_circuit/garbled_circuit.h"

void PerformObliviousInference(const HWGN2Params& params) {
    // Step 1: Convert input data into a format suitable for HWGN2 and TinyLEGO
    std::string converted_input = "converted_input.bin";
    FILE* input_file = fopen(params.input_file.c_str(), "rb");
    if (!input_file) {
        std::cerr << "Error: Unable to open input file: " << params.input_file << std::endl;
        return;
    }

    // Assuming conversion logic for HWGN2 input format
    FILE* converted_file = fopen(converted_input.c_str(), "wb");
    float buffer[256]; // Example buffer for batch processing
    while (fread(buffer, sizeof(float), 256, input_file)) {
        // Perform any necessary transformations here (if required)
        fwrite(buffer, sizeof(float), 256, converted_file);
    }
    fclose(input_file);
    fclose(converted_file);

    // Step 2: Run TinyLEGO to preprocess the input data
    std::vector<std::string> tiny_args = {
        "Tinyconst",
        "-n", std::to_string(params.num_iters),
        "-c", params.circuit_file,
        "-ip", params.ip_address,
        "-p", std::to_string(params.port)
    };

    std::vector<const char*> tiny_c_args;
    for (const auto& arg : tiny_args) {
        tiny_c_args.push_back(arg.c_str());
    }

    main(static_cast<int>(tiny_c_args.size()), tiny_c_args.data());

    // Step 3: Pass preprocessed data to HWGN2 for oblivious inference
    std::string hwgn2_output = params.output_file;

    // Use HWGN2 API or function call
    HWGN2Inference(params.circuit_file, "", "", hwgn2_output, params.num_iters, params.port, params.use_fpga);

    std::cout << "Oblivious inference completed. Results saved to: " << hwgn2_output << std::endl;
}
