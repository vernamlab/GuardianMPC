#!/bin/bash

# Compile the program
g++ HWGN2_WRAPPER.cpp ExampleUsage.cpp -o ObliviousInference -I../Private_training/TinyLEGO-master/include -IHWGN2-main/TinyGarble/garbled_circuit

# Run the program
./ObliviousInference
