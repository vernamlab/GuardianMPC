#include "Wrapper.h"

int main() {
    // Define a 3D dataset
    size_t dim1 = 10, dim2 = 20, dim3 = 30;
    float*** dataset = new float**[dim1];
    for (size_t i = 0; i < dim1; ++i) {
        dataset[i] = new float*[dim2];
        for (size_t j = 0; j < dim2; ++j) {
            dataset[i][j] = new float[dim3];
            for (size_t k = 0; k < dim3; ++k) {
                dataset[i][j][k] = static_cast<float>(i + j + k);
            }
        }
    }

    // Define 2D weights array
    size_t weights_dim1 = 5, weights_dim2 = 5;
    float** weights = new float*[weights_dim1];
    for (size_t i = 0; i < weights_dim1; ++i) {
        weights[i] = new float[weights_dim2];
    }

    // Define parameters
    TinyParams params;
    params.num_iters = 10;
    params.circuit_name = "aes";
    params.num_execs = {8, 2, 1};
    params.optimize_online = 0;
    params.ip_address = "10.11.100.216";
    params.port = 28001;
    params.circuit_file = "";

    // Process the dataset and populate weights
    ProcessDataset(&dataset[0][0][0], dim1, dim2, dim3, weights, weights_dim1, weights_dim2, params);

    // Cleanup
    for (size_t i = 0; i < dim1; ++i) {
        for (size_t j = 0; j < dim2; ++j) {
            delete[] dataset[i][j];
        }
        delete[] dataset[i];
    }
    delete[] dataset;

    for (size_t i = 0; i < weights_dim1; ++i) {
        delete[] weights[i];
    }
    delete[] weights;

    return 0;
}
