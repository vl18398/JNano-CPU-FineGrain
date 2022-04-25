# JNano-CPU-FineGrain
# Power Modelling of ARM Cortex-A57 CPU on NVIDIA Jetson Nano

*******************************************************************************
# Step 1: Data Collection (Requires NVIDIA Jetson Nano)
1)  In each of the config_*benchmarkname* files, change the register address values to correspond to the target PMU group
2)  In line 29 of cpu_pow_mon.c, change the PMU event names to correlate to the desired PMU register addresses
3)  Run the makefile to compile the files: 
            make -f Makefile_cpu cpu_pow
4)  Run executable to start the benchmark run and collect data: 
            sudo ./pmon_cpu
5)  Raw data file is dumped: 
            data_store.dat
*******************************************************************************

# Step 2: Power Modelling and Validation
1)  Convert data_store.dat to a .txt file
2)  Go to ModellingAndValidation/
3)  Ensure the following files are present in the directory:
	   benchmark_split.txt
	   build_model.m,
	   load_build_model.m,
	   octave_makemodel.sh (Make it executable using chmod u+x
    octave_makemodel.sh), and
	   fine-grain-CPU-data-parsec.txt
4)  Generate and Validate the power model by launching the command: 
            make make_cpu_model
5)  The model details can be output into an output log using the -s option
6)  Use ./octave_makemodel.sh -h to open the help menu

#################################################################################

CREDITS:
1)  Dr Jose Nunez Yanez, Department of Electrical and Electronic Engineering, University of Bristol
2)  Dr Kris Nikov, Department of Computer Science, University of Bristol
3)  Varun Anand, MSc Microelectronics Student, University of Bristol

This project work serves as an extension to the work carried out on the NVIDIA Jetson boards by Dr Jose Nunez-Yanez
and Dr Kris Nikov.
It also leads on from the work completed by MSc student Varun Anand, for the ARM Cortex-A57 CPU.
*********************************************************************************

REFERENCES:
1)  GPU Power Model: https://github.com/kranik/ARMPM_BUILDMODEL/tree/GPU_tx1
2)  Original Modelling scripts adopted from Dr Kris Nikov's Doctoral Thesis
    project: https://github.com/kranik/ARMPM_BUILDMODEL/tree/master
3)  Kris Nikov. Robust Energy and Power Predictor Selection. url: 
    https://github.com/TSL-UOB/TP-REPPS
4)  Kris Nikov and Jose Nunez-Yanez. "Intra and Inter-Core Power Modelling
    for Single-ISA Heterogeneous Processors". In: International Journal
    of Embedded Systems (2020)

#################################################################################
