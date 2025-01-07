#ifndef WRAPPER_H
#define WRAPPER_H

#include <string>
#include <vector>

struct TinyParams {
    int num_iters;
    std::string circuit_name;
    std::vector<int> num_execs;
    int optimize_online;
    std::string ip_address;
    int port;
    std::string circuit_file;
};

void ProcessDataset(const float* dataset, size_t dim1, size_t dim2, size_t dim3, float** weights, size_t weights_dim1, size_t weights_dim2, const TinyParams& params);

#endif // WRAPPER_H
