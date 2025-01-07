#include "HWGN2_WRAPPER.h"

int main() {
    HWGN2Params params;
    params.num_iters = 10;
    params.circuit_file = "../Private_training/TinyLEGO-master/circuits/MLP.circuit";
    params.input_file = "data/input_data.bin";
    params.output_file = "data/output_results.bin";
    params.ip_address = "127.0.0.1";
    params.port = 12345;
    params.use_fpga = 1; // Enable FPGA acceleration

    PerformObliviousInference(params);

    return 0;
}
