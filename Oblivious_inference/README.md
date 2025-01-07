## Features

- **Oblivious Inference**: Securely evaluate neural networks without revealing sensitive data.
---

## Repository Structure

- **`HWGN2_WRAPPER.h`**: Header file defining the interface for oblivious inference.
- **`HWGN2_WRAPPER.cpp`**: Implementation of the oblivious inference workflow, integrating TinyLEGO and HWGN2.
- **`ExampleUsage.cpp`**: Example demonstrating how to use the wrapper for oblivious inference.
- **`run_inference.sh`**: Shell script to compile and run the oblivious inference program.
- **`HWGN2-main`**: Contains HWGN2 garbled circuit files for evaluation.
- **`Private_training/TinyLEGO-master/src/tiny-mains`**: Contains TinyLEGO's `tiny-const-main.cpp` and `tiny-eval-main.cpp` files for preprocessing.
- **`data`**: Directory for input and output files.

---

## Setup Instructions

### 1. Prerequisites

1. **C++ Compiler**: Ensure you have a modern C++ compiler installed (e.g., `g++`).
2. **Dependencies**:
   - Install libraries for TinyLEGO and HWGN2 (follow their respective setup guides).
   - Install FPGA tools (e.g., Xilinx Vivado) if using hardware acceleration.
3. **Data**:
   - Prepare your input dataset in binary format (`data/input_data.bin`).

---

### 2. Files and Directory Structure

Ensure the following directory structure:

```
GuardianMPC/
├── HWGN2_WRAPPER.h
├── HWGN2_WRAPPER.cpp
├── ExampleUsage.cpp
├── run_inference.sh
├── HWGN2-main/
│   └── TinyGarble/garbled_circuit/
├── Private_training/
│   └── TinyLEGO-master/
│       └── src/tiny-mains/
├── data/
    ├── input_data.bin
    ├── output_results.bin
```

---

### 3. Compilation

Use the provided shell script to compile the files:

```bash
chmod +x run_inference.sh
./run_inference.sh
```

Alternatively, compile manually:

```bash
g++ HWGN2_WRAPPER.cpp ExampleUsage.cpp -o ObliviousInference     -I../Private_training/TinyLEGO-master/include     -IHWGN2-main/TinyGarble/garbled_circuit
```

---

### 4. Usage

After compilation, run the program:

```bash
./ObliviousInference
```

This will:

1. **Preprocess Input**: Use TinyLEGO to preprocess the input dataset.
2. **Oblivious Inference**: Use HWGN2 to securely evaluate the neural network.
3. **Save Output**: Store inference results in `data/output_results.bin`.

---

### Example Setup in `ExampleUsage.cpp`

```cpp
#include "HWGN2_WRAPPER.h"

int main() {
    HWGN2Params params;
    params.num_iters = 10;  // Number of evaluation iterations
    params.circuit_file = "../Private_training/TinyLEGO-master/circuits/MLP.circuit";
    params.input_file = "data/input_data.bin";  // Path to input dataset
    params.output_file = "data/output_results.bin";  // Path to save results
    params.ip_address = "127.0.0.1";  // IP for communication
    params.port = 12345;  // Port for communication
    params.use_fpga = 1;  // Set to 1 for FPGA, 0 for CPU

    PerformObliviousInference(params);

    return 0;
}
```

---

### 5. Input and Output

- **Input**: The input dataset (`data/input_data.bin`) should be a binary file containing the neural network's input data.
- **Output**: The results will be saved in `data/output_results.bin`. This file contains the inference results securely computed by the framework.

---

### Additional Notes

- **FPGA Acceleration**: Ensure your FPGA is configured and connected. Modify `params.use_fpga` to toggle between FPGA and CPU modes.
- **Integration with Neural Networks**: Replace `MLP.circuit` with the circuit file for your specific neural network architecture.
- **TinyLEGO and HWGN2**: For detailed usage of TinyLEGO and HWGN2, refer to their respective documentation.

---

### Troubleshooting

1. **Compilation Errors**:
   - Ensure all include paths (`-I`) are correctly set.
   - Verify dependencies for TinyLEGO and HWGN2 are installed.
2. **Runtime Errors**:
   - Check that the input dataset exists and is correctly formatted.
   - Ensure FPGA tools are installed if using hardware acceleration.

---

### References

- [HWGN2 GitHub Repository](https://github.com/vernamlab/HWGN2)
- [TinyLEGO GitHub Repository](https://github.com/yourusername/TinyLEGO)
- *"GuardianMPC: Backdoor-resilient Neural Network Computation"* by Hashemi et al.

---
