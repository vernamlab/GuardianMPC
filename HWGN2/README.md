# HWGN2
HWGN2 is a garbled DL hardware accelerator on an Artix-7 FPGA. By tailoring the concepts known only for software garbled DL accelerator to the needs of a hardware DL accelerator, the implementation of such accelerator is enhanced: HWGN2 requires up to 62.5× fewer logical and 66× less memory utilization compared to the state-of-art approaches. This is indeed possible at the price of more communication overhead. HWGN2 provides users the flexibility to protect their NN IP both in real-time applications and in applications where the hardware resources are limited by hardware resource utilization or communication cost. For more information, please refer to [HWGN2: Side-channel Protected Neural Networks through Secure and Private Function Evaluation]([https://dl.acm.org/doi/abs/10.1145/3508352.3549455](https://arxiv.org/abs/2208.03806)).
# Dependencies:
Install dependencies on Ubuntu:
g++: 
```
 $ sudo apt-get install g++
```
OpenSSL: 
```
  $ sudo apt-get install libssl-dev
```
boost:
```
  $ sudo apt-get install libboost-all-dev
```
cmake:
```
  $ sudo apt-get install software-properties-common
  $ sudo add-apt-repository ppa:george-edison55/cmake-3.x
  $ sudo apt-get update
  $ sudo apt-get upgrade
  $ sudo apt-get install cmake
```
TinyGarble:
```
  $ cd TintGarbe 
  $./configure
  $ cd bin
  $ make
```
ARM2GC:
```
  $ sudo apt install binutils-arm-linux-gnueabi
  $ sudo apt install gcc-arm-linux-gnueabi
```
TinyGarble2: 
```
  $ git clone https://github.com/IntelLabs/TinyGarble2.0.git
  $ git clone https://github.com/IntelLabs/emp-tool.git
  $ git clone https://github.com/IntelLabs/emp-ot.git
  $ sudo ./TinyGarble2.0/install_scripts/install_dependencies.sh
  $ cd emp-tool
  $ cmake . -DCMAKE_INSTALL_PREFIX=<install_path>
  $ make -j 
  $ make install -j
  $ cd ..
  $ cd emp-ot
  $ cmake . -DCMAKE_INSTALL_PREFIX=<install_path>
  $ make -j 
  $ make install -j 
  $ cd ..
  $ cd TinyGarble2.0
  $ cmake . -DCMAKE_INSTALL_PREFIX=<install_path>
  $ make -j 
  $ make install -j
```
# SCD generation:
V2SCD_Main: Translating netlist Verilog (.v) file to simple circuit description (.scd) file
```
  -h [ --help ]                         produce help message.
  -i [ --netlist ]
                                        Input netlist (verilog .v) file
                                        address.
  -o [ --scd ]
                                        Output simple circuit description (scd)
                                        file address.
```
# Run:
For circuit synthesize go to this directory:
``` 
$cd TinyGarble/circuit_synthesis
```
Generate p_init.text as follows:  
First, go to your benchmark directory:
```
  $ cd <benchmark_directory>
```
Then compile the source code and write the Assembly instructions to ```p_init```:  
```
  $ HWGN2/TinyGarble/bin/garbled_circuit/TinyGarble -a -i HWGN2/TinyGarble/bin/scd/netlists/a23_gc_main_64_w_n_cc.scd --p_init a23/<benchmark_directory>/p.txt --init a23/<benchmark_directory>/test/g.txt -c 1000 -t 1 --log2std
```
Last step:  
Provide the ```p_init```, ```e_init```, and ```g_init``` to HWGN2/MIPS_Garbled_Evaluator_Core_high_performance_scenario/Garbled_MIPS_netlist_high_performance.v for high performance scenario or HWGN2/MIPS_Garbled_Evaluator_Core_improved_resource_efficiency/Garbled_MIPS_netlist_high_performance.v for improved resource efficiency scenario.  
Synthesize and run the HWGN2/MIPS_Garbled_Evaluator_Core_improved_resource_efficiency/Garbled_MIPS_netlist_high_performance.v for improved resource efficiency scenario.
# References:
How to cite this code:
@inproceedings{hashemi2022hwgn,
  title={HWGN 2: Side-Channel Protected NNs Through Secure and Private Function Evaluation},
  author={Hashemi, Mohammad and Roy, Steffi and Forte, Domenic and Ganji, Fatemeh},
  booktitle={International Conference on Security, Privacy, and Applied Cryptography Engineering},
  pages={225--248},
  year={2022},
  organization={Springer}
}
1. Ebrahim M. Songhori, Siam U. Hussain, Ahmad-Reza Sadeghi, Thomas Schneider and Farinaz Koushanfar, "TinyGarble: Highly Compressed and Scalable Sequential Garbled Circuits." Security and Privacy, 2015 IEEE Symposium on May, 2015.
1. Hussain, Siam, et al. "TinyGarble2: Smart, Efficient, and Scalable Yao's Garble Circuit." Proceedings of the 2020 Workshop on Privacy-Preserving Machine Learning in Practice. 2020.
1. Mukherjee, Rajdeep, Michael Tautschnig, and Daniel Kroening. "v2c–A verilog to C translator." Tools and Algorithms for the Construction and Analysis of Systems: 22nd International Conference, TACAS 2016, Held as Part of the European Joint Conferences on Theory and Practice of Software, ETAPS 2016, Eindhoven, The Netherlands, April 2-8, 2016, Proceedings 22. Springer Berlin Heidelberg, 2016.
1. Cao, Junwei. "ARMSim: A modeling and simulation environment for agent-based grid computing." Simulation 80.4-5 (2004): 221-229.
