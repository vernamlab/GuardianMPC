## Features

- **Private Training**: Train neural networks on private datasets while protecting model weights and training data from adversaries.

### Repository Structure

- **`Wrapper.h`**: Header file defining the interface for the private training wrapper.
- **`Wrapper_Implementation.cpp`**: Implementation of the wrapper to integrate private training and evaluation.
- **`ExampleUsage.cpp`**: Example usage file demonstrating how to train a neural network using the provided implementation.

### How to Use

1. **Clone the Repository**

   ```bash
   git clone https://github.com/yourusername/GuardianMPC.git
   cd GuardianMPC
   ```

2. **Set Up Your Dataset**

   Prepare your dataset as a 3D array (`float dataset[dim1][dim2][dim3]`). The dimensions can be adjusted based on your neural network's input size. Store the dataset in binary format if necessary.

3. **Modify Parameters**

   Edit the `ExampleUsage.cpp` file to set the required parameters:
   - Number of iterations
   - Neural network circuit file
   - Optimization flags
   - IP address and port for communication

4. **Compile the Code**

   ```bash
   g++ Wrapper_Implementation.cpp ExampleUsage.cpp -o GuardianMPC
   ```

5. **Run the Training**

   Execute the compiled binary:

   ```bash
   ./GuardianMPC
   ```

   The training process will securely compute the model weights and output the results into the specified 2D weights array.

### Example

Here’s an example setup for a neural network training task:

```cpp
#include "Wrapper.h"

int main() {
    // Example Dataset: Dimensions 10x20x30
    float dataset[10][20][30] = { /* Initialize your data */ };

    // Output weights array (2D)
    float weights[10][10] = {0};

    // Parameters for GuardianMPC
    TinyParams params;
    params.num_iters = 10;
    params.circuit_name = "mlp_circuit";
    params.num_execs = {8, 2, 1};
    params.optimize_online = 1;
    params.ip_address = "127.0.0.1";
    params.port = 12345;

    // Process dataset and obtain weights
    ProcessDataset(&dataset[0][0][0], 10, 20, 30, weights, 10, 10, params);

    return 0;
}
```

### Additional Notes

- **Paper Reference**: For detailed information on the GuardianMPC methodology and performance evaluation, refer to the paper *"GuardianMPC: Backdoor-resilient Neural Network Computation"* by Hashemi et al.
- **Hardware Acceleration**: If using FPGA acceleration, ensure the hardware is correctly configured as described in the experimental setup section of the paper.
