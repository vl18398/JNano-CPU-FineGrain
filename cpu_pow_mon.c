/*
		File: cpu_pow_mon.c
		Description:	This file is the top file to control the frequencies to be set
		and launches the scripts to start the benchmark run
*/

#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#include "PMU_transfer.h"
#include "jnano_inst.h"
#include "unistd.h"

int main(void) {
	printf("\n\t\t -------------------cpu_pow_mon.c-------------------\n");	

	printf("\n\t\t CPU POW MON:: Starting power monitor...\n");

	int freqs[39] = {102000,102000,102000, 204000,204000,204000, 307200,307200,307200, 403200,403200,403200, 518400,518400,518400, 614400,614400,614400, 710400,710400,710400, 921600,921600,921600, 1036800,1036800,1036800, 1132800,1132800,1132800, 1224000,1224000,1224000, 1428000,1428000,1428000, 1479000, 1479000, 1479000};	//CPU frequency in kHz

	char cmdbuf[256];

	FILE *fp_log;
	fp_log = fopen("data_store.dat", "w");
	if (!fp_log) {
		printf("cannot open data_store.dat file \n ");	
	}

	fprintf(fp_log, "Run Duration (ms)\tBenchmark\tCPU Frequency (MHz)\tCPU Temperature(C)\tVoltage[V]\tPower[W]\tCPU_CYCLES\tBR_MIS_PRED\tBR_PRED\tMEM_ACCESS\tL1I_CACHE\tL1D_CACHE_WB\n");

	fflush(fp_log);	
	fclose(fp_log);


	printf("\n\t\t -------------------blackscholes-------------------\n");
	for(int cfreq=0;cfreq<39;cfreq++)		// 13 frequencies in all : ALL trials
	{
		printf("\t cpu_pow_mon.c::main() : Setting CPU frequency (kHz) to %d\n",freqs[cfreq]);

		snprintf(cmdbuf,sizeof(cmdbuf),"./cpu_clocks.sh --set %d",freqs[cfreq]);
		system(cmdbuf);
		
		printf("Launching fine_grain_recorder_blackscholes...\n");
		system("./config_master_blackscholes.sh");
		printf("\tFinished fine_grain_recorder_blackscholes...\n");

		printf("\tLaunching PMU event transfer...\n");
		transferPMUdata(); 		//transfer PMU events data
		printf("\tFinished PMU event transfer...\n");
	
		printf("\tFormating data and uploading...\n");
		system("python3 ./format_data.py blackscholes");
		system("python3 ./update_data_master.py");
		printf("\tData uploaded...\n");
	}

	printf("\t Finishing power monitor for blackscholes...\n");


	printf("\n\t\t -------------------bodytrack-------------------\n");
	for(int cfreq=0;cfreq<39;cfreq++)		// 13 frequencies in all : ALL trials
	{
		printf("\t cpu_pow_mon.c::main() : Setting CPU frequency (kHz) to %d\n",freqs[cfreq]);

		snprintf(cmdbuf,sizeof(cmdbuf),"./cpu_clocks.sh --set %d",freqs[cfreq]);
		system(cmdbuf);
		
		printf("Launching fine_grain_recorder_bodytrack...\n");
		system("./config_master_bodytrack.sh");
		printf("\tFinished fine_grain_recorder_bodytrack...\n");

		printf("\tLaunching PMU event transfer...\n");
		transferPMUdata(); 		//transfer PMU events data
		printf("\tFinished PMU event transfer...\n");
	
		printf("\tFormating data and uploading...\n");
		system("python3 ./format_data.py bodytrack");
		system("python3 ./update_data_master.py");
		printf("\tData uploaded...\n");
	}

	printf("\t Finishing power monitor for bodytrack...\n");


	printf("\n\t\t -------------------dedup-------------------\n");
	for(int cfreq=0;cfreq<39;cfreq++)		// 13 frequencies in all : ALL trials
	{
		printf("\t cpu_pow_mon.c::main() : Setting CPU frequency (kHz) to %d\n",freqs[cfreq]);

		snprintf(cmdbuf,sizeof(cmdbuf),"./cpu_clocks.sh --set %d",freqs[cfreq]);
		system(cmdbuf);
		
		printf("Launching fine_grain_recorder_dedup...\n");
		system("./config_master_dedup.sh");
		printf("\tFinished fine_grain_recorder_dedup...\n");

		printf("\tLaunching PMU event transfer...\n");
		transferPMUdata(); 		//transfer PMU events data
		printf("\tFinished PMU event transfer...\n");
	
		printf("\tFormating data and uploading...\n");
		system("python3 ./format_data.py dedup");
		system("python3 ./update_data_master.py");
		printf("\tData uploaded...\n");
	}

	printf("\t Finishing power monitor for dedup...\n");


	printf("\n\t\t -------------------fluidanimate-------------------\n");
	for(int cfreq=0;cfreq<39;cfreq++)		// 13 frequencies in all : ALL trials
	{
		printf("\t cpu_pow_mon.c::main() : Setting CPU frequency (kHz) to %d\n",freqs[cfreq]);

		snprintf(cmdbuf,sizeof(cmdbuf),"./cpu_clocks.sh --set %d",freqs[cfreq]);
		system(cmdbuf);
		
		printf("Launching fine_grain_recorder_fluidanimate...\n");
		system("./config_master_fluidanimate.sh");
		printf("\tFinished fine_grain_recorder_fluidanimate...\n");

		printf("\tLaunching PMU event transfer...\n");
		transferPMUdata(); 		//transfer PMU events data
		printf("\tFinished PMU event transfer...\n");
	
		printf("\tFormating data and uploading...\n");
		system("python3 ./format_data.py fluidanimate");
		system("python3 ./update_data_master.py");
		printf("\tData uploaded...\n");
	}

	printf("\t Finishing power monitor for fluidanimate...\n");


	printf("\n\t\t -------------------freqmine-------------------\n");
	for(int cfreq=0;cfreq<39;cfreq++)		// 13 frequencies in all : ALL trials
	{
		printf("\t cpu_pow_mon.c::main() : Setting CPU frequency (kHz) to %d\n",freqs[cfreq]);

		snprintf(cmdbuf,sizeof(cmdbuf),"./cpu_clocks.sh --set %d",freqs[cfreq]);
		system(cmdbuf);
		
		printf("Launching fine_grain_recorder_freqmine...\n");
		system("./config_master_freqmine.sh");
		printf("\tFinished fine_grain_recorder_freqmine...\n");

		printf("\tLaunching PMU event transfer...\n");
		transferPMUdata(); 		//transfer PMU events data
		printf("\tFinished PMU event transfer...\n");
	
		printf("\tFormating data and uploading...\n");
		system("python3 ./format_data.py freqmine");
		system("python3 ./update_data_master.py");
		printf("\tData uploaded...\n");
	}

	printf("\t Finishing power monitor for freqmine...\n");

	
	printf("\n\t\t -------------------streamcluster-------------------\n");
	for(int cfreq=0;cfreq<39;cfreq++)		// 13 frequencies in all : ALL trials
	{
		printf("\t cpu_pow_mon.c::main() : Setting CPU frequency (kHz) to %d\n",freqs[cfreq]);

		snprintf(cmdbuf,sizeof(cmdbuf),"./cpu_clocks.sh --set %d",freqs[cfreq]);
		system(cmdbuf);
		
		printf("Launching fine_grain_recorder_streamcluster...\n");
		system("./config_master_streamcluster.sh");
		printf("\tFinished fine_grain_recorder_streamcluster...\n");

		printf("\tLaunching PMU event transfer...\n");
		transferPMUdata(); 		//transfer PMU events data
		printf("\tFinished PMU event transfer...\n");
	
		printf("\tFormating data and uploading...\n");
		system("python3 ./format_data.py streamcluster");
		system("python3 ./update_data_master.py");
		printf("\tData uploaded...\n");
	}

	printf("\t Finishing power monitor for streamcluster...\n");


	printf("\n\t\t -------------------vips-------------------\n");
	for(int cfreq=0;cfreq<39;cfreq++)		// 13 frequencies in all : ALL trials
	{
		printf("\t cpu_pow_mon.c::main() : Setting CPU frequency (kHz) to %d\n",freqs[cfreq]);

		snprintf(cmdbuf,sizeof(cmdbuf),"./cpu_clocks.sh --set %d",freqs[cfreq]);
		system(cmdbuf);
		
		printf("Launching fine_grain_recorder_vips...\n");
		system("./config_master_vips.sh");
		printf("\tFinished fine_grain_recorder_vips...\n");

		printf("\tLaunching PMU event transfer...\n");
		transferPMUdata(); 		//transfer PMU events data
		printf("\tFinished PMU event transfer...\n");
	
		printf("\tFormating data and uploading...\n");
		system("python3 ./format_data.py vips");
		system("python3 ./update_data_master.py");
		printf("\tData uploaded...\n");
	}

	printf("\t Finishing power monitor for vips...\n");

	printf("\t Finished all measurements, returning CPU freq to max...\n");	

	snprintf(cmdbuf,sizeof(cmdbuf),"./cpu_clocks.sh --set %d",1479000);
	system(cmdbuf);

	return 0;	
}







