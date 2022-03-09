#!/bin/bash




sudo parallel ::: ./config_physical_sensors.sh ./config_dedup.sh

exit 0


