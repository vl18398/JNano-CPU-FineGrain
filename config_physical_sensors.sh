#!/bin/bash

{
while (( SECONDS <= 20))
do
	sudo cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq
	sudo cat /sys/devices/virtual/thermal/thermal_zone1/temp
	sudo cat /sys/bus/i2c/drivers/ina3221x/6-0040/iio:device0/in_voltage2_input
	sudo cat /sys/bus/i2c/drivers/ina3221x/6-0040/iio:device0/in_power2_input
done
} > ./sensor_data.txt
echo "done"
exit 0


