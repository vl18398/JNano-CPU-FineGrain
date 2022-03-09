#!/bin/bash




sudo perf stat -o perf_hw_counters.txt -e r011,r010,r012,r013,r014,r015 -I 500 -x "\t" ./parsec-3.0/bin/parsecmgmt -a run -p freqmine



exit 0


