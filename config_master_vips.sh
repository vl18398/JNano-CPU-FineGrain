#!/bin/bash




sudo parallel ::: ./config_physical_sensors.sh ./config_vips.sh

exit 0


