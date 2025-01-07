#ifndef HWGN2_WRAPPER_H
#define HWGN2_WRAPPER_H

#include <string>
#include <vector>

struct HWGN2Params {
    int num_iters;
    std::string circuit_file;    // Path to the TinyLEGO circuit file
    std::string input_file;      // Input data file for HWGN2
    std::string output_file;     // Output data file for inference results
    std::string ip_address;      // IP address for communication
    int port;                    // Port for communication
    int use_fpga;                // 1 to enable FPGA acceleration, 0 for CPU only
};

void PerformObliviousInference(const HWGN2Params& params);

#endif // HWGN2_WRAPPER_H
