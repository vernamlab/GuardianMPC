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
