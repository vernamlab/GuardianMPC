# GuardianMPC
A Backdoor-resilient Deep Learning Accelerator
## Description
Advancements in deep learning (DL) have unlocked unprecedented capabilities in various
domains. However, alongside these advancements, the susceptibility of DL models to backdoor insertion
attacks has become a significant concern. These attacks mimic the actions of a malicious adversary and can
remain undetected under conventional security paradigms. MPC’s interactive computation approach aligns
well with the need to counter backdoor attacks. In this work, we aim to build a bridge between MPC, and
particularly, secure and private two-party computation, and the countermeasures against backdoor attacks.
In doing so, we introduce GurdianMPC, a DL accelerator that employ the LEGO family of protocols to
provide not only security against backdoor attacks, but also users with data privacy. Moreover, by leveraging
optimization techniques tailored toward hardware acceleration, GurdianMPC achieves high efficiency and
low latency. Specifically, our implementation on Field Programmable Gate Arrays (FPGAs) computational
power evaluate a typical NN up to 13.44× faster during the online phase compared to its counterpart running
on software, with a trade-off against a negligible offline computation time.
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
References
---
* [1] M. Hashemi, S. Roy, D. Forte, F. Gangi, “HWGN2: Side-Channel Protected NNs Through Secure and Private Function Evaluation,”  Security, Privacy, and Applied Cryptography Engineering (SPACE22), vol. 13783, pp. 225-248, 2022. [Online]. Available: https://link.springer.com/chapter/10.1007/978-3-031-22829-2_13.

* [2] T. K. Frederiksen, T. P. Jakobsen, J. B. Nielsen, R. Trifiletti, “TinyLEGO: An Interactive Garbling Scheme for Maliciously Secure Two-Party Computation,” IACR Cryptology ePrint Archive, vol. 2015, p. 309, 2015. [Online]. Available: http://ia.cr/2015/309.

* [3] J. B. Nielsen, T. Schneider, R. Trifiletti, "Constant Round Maliciously Secure 2PC with Function-independent Preprocessing using LEGO", in The Network and Distributed System Security Symposium (NDSS) 2017. Availible: http://ia.cr/2016/1069.
