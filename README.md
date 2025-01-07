# GuardianMPC
**A Backdoor-Resilient Deep Learning Accelerator**

---

## Description

The rapid advancements in deep learning (DL) have unlocked unprecedented capabilities across various domains. However, these advancements have also introduced new security challenges, particularly the vulnerability of DL models to **backdoor attacks**. These attacks often mimic the actions of a malicious adversary and can remain undetected under conventional security paradigms.

**GuardianMPC** bridges the gap between **Secure Multiparty Computation (MPC)**, particularly **two-party computation (2PC)**, and robust countermeasures against backdoor attacks. By employing the LEGO family of protocols, GuardianMPC not only protects against backdoor attacks but also ensures **data privacy** for users. Additionally, with optimization techniques tailored for hardware acceleration, GuardianMPC delivers high efficiency and low latency.

Our implementation achieves:
- **13.44× faster evaluation** during the online phase on FPGAs compared to software counterparts, with a negligible trade-off in offline computation time.
- **Secure and private training** of DL models.
- **Oblivious inference**, ensuring privacy and secure evaluation.

---

## Features

### 1. Private Training
GuardianMPC provides tools to train neural networks securely using **TinyLEGO**. This protects both the training data and the resulting model from adversaries.

### 2. Oblivious Inference
Securely evaluate neural networks using **TinyLEGO** and **HWGN2**. GuardianMPC supports both CPU-based and FPGA-accelerated inference for high performance.

### 3. Hardware Acceleration
GuardianMPC leverages FPGA-based optimizations to reduce latency and improve throughput during secure computations.

---

## Installation

To set up GuardianMPC, install the following dependencies:

### System Dependencies (Ubuntu)
```bash
# Install g++
sudo apt-get install g++

# Install OpenSSL
sudo apt-get install libssl-dev

# Install Boost
sudo apt-get install libboost-all-dev

# Install CMake
sudo apt-get install software-properties-common
sudo add-apt-repository ppa:george-edison55/cmake-3.x
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install cmake
```

### TinyGarble
```bash
# Clone and build TinyGarble
cd TinyGarble
./configure
cd bin
make
```

### ARM2GC
```bash
sudo apt install binutils-arm-linux-gnueabi
sudo apt install gcc-arm-linux-gnueabi
```

### TinyGarble2
```bash
git clone https://github.com/IntelLabs/TinyGarble2.0.git
git clone https://github.com/IntelLabs/emp-tool.git
git clone https://github.com/IntelLabs/emp-ot.git

# Install dependencies
sudo ./TinyGarble2.0/install_scripts/install_dependencies.sh

# Build EMP-Tool
cd emp-tool
cmake . -DCMAKE_INSTALL_PREFIX=<install_path>
make -j 
make install -j
cd ..

# Build EMP-OT
cd emp-ot
cmake . -DCMAKE_INSTALL_PREFIX=<install_path>
make -j 
make install -j
cd ..

# Build TinyGarble2
cd TinyGarble2.0
cmake . -DCMAKE_INSTALL_PREFIX=<install_path>
make -j 
make install -j
```

---

## Usage

### Private Training
To securely train a neural network using GuardianMPC:
1. Navigate to the `Private_training` folder.
2. Follow the instructions provided in the **Private Training README** file to prepare your dataset and train your model.

The key features of private training include:
- Secure computation using TinyLEGO.
- Support for various neural network architectures.
- Protection against adversarial attacks during training.

---

### Oblivious Inference
To perform oblivious inference:
1. Navigate to the `Oblivious Inference` folder.
2. Follow the instructions in the **Oblivious Inference README** file to prepare the input dataset and run the inference.

The oblivious inference workflow:
- Preprocess the input using TinyLEGO.
- Perform secure inference using HWGN2.
- Supports both FPGA-based and CPU-based evaluation.

---

## Directory Structure

```
GuardianMPC/
├── Private_training/              # Scripts and tools for private training
│   └── TinyLEGO-master/           # TinyLEGO library
│       └── src/tiny-mains/        # Secure computation sources
├── Oblivious_inference/           # Scripts and tools for oblivious inference
│   ├── HWGN2-main/                # HWGN2 garbled circuit files
│   ├── ExampleUsage.cpp           # Example for oblivious inference
│   ├── HWGN2_WRAPPER.cpp          # Wrapper for TinyLEGO + HWGN2 integration
│   └── run_inference.sh           # Shell script to compile and run
├── data/                          # Input and output data
└── README.md                      # Main repository README
```

---

## References

1. **HWGN2**: *"Side-Channel Protected NNs Through Secure and Private Function Evaluation,"* Security, Privacy, and Applied Cryptography Engineering (SPACE22), vol. 13783, pp. 225-248, 2022. [Online](https://link.springer.com/chapter/10.1007/978-3-031-22829-2_13).

2. **TinyLEGO**: *"An Interactive Garbling Scheme for Maliciously Secure Two-Party Computation,"* IACR Cryptology ePrint Archive, vol. 2015, p. 309, 2015. [Online](http://ia.cr/2015/309).

3. **GuardianMPC Paper**: *"Backdoor-Resilient Neural Network Computation."*

---