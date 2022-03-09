/*
	File:	PMU_transfer.c
	Author:	Matthew Burgess

	Reads essential counters from perf stat output file and transfers them into another .txt

*/


#define _GNU_SOURCE
#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include "jnano_inst.h"
#include "PMU_transfer.h"

typedef unsigned int uint32_t;

FILE *fp_log;
FILE *cl_log;

void transferPMUdata(){

	printf("\n\t\t -------------------now transfering PMU data-------------------\n");

	FILE* filell = fopen("perf_hw_counters.txt", "r");
 	FILE* fpll = fopen("read_hw_events.txt", "w+");
    	char line[256]; 
  	char str1[20]; 
	char str2[20];    
	char str3[20]; 	
	char result;
    	while (fgets(line, sizeof(line), filell)) { 
        	sscanf(line, "%s\t %s\t %s\t", str1, str2, str3); 
        	printf("%s\t", str2); 
		fprintf(fpll,"%s\t %s\t %s\n", str1, str2, str3) ;
   		}

	printf("\n");
   	fclose(filell);
	fclose(fpll);
}
