#!/bin/bash




sudo parallel ::: ./config_physical_sensors.sh ./config_streamcluster.sh

exit 0


