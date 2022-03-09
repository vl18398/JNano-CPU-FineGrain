import sys

sensor_file = open("sensor_data.txt", "r")
new_line = []
for line in sensor_file:
    new_line.append(line)
sensor_file.close()

stripped_array = [s.strip() for s in new_line]
temp_line = []
filled_line = []
master_sensor_array =[]
i=0
for item in stripped_array:
    if i < 4:
        temp_line.append(item)
        i+=1
    if i == 4:
        filled_line = temp_line
        master_sensor_array.append(filled_line.copy())
        temp_line.clear()
        i=0

pmu_file_src = open("read_hw_events.txt", "r")
pmu_file = (pmu_file_src.readlines()[2:])
pmu_new_line = []
for line in pmu_file:
    pmu_new_line.append(line)
pmu_file_src.close()

formatted_pmu_array = []
stripped_pmu_array= [s.strip() for s in pmu_new_line]
for item in stripped_pmu_array:
    item.split()
    item = item[:-5]
    item = item.replace("\t", "")
    item = item.split(" ")
    formatted_pmu_array.append(item)


count=0
master_pmu_array = []
temp_pmu_line = []
for entry in formatted_pmu_array:
    if count == 0:
        temp_pmu_line.append(entry[0])
        temp_pmu_line.append(entry[1])
        count += 1
    elif count == 1:
        temp_pmu_line.append(entry[1])
        count +=1
    elif count == 2:
        temp_pmu_line.append(entry[1])
        count +=1
    elif count == 3:
        temp_pmu_line.append(entry[1])
        count +=1
    elif count == 4:
        temp_pmu_line.append(entry[1])
        count +=1
    elif count == 5:
        temp_pmu_line.append(entry[1])
        master_pmu_array.append(temp_pmu_line)
        temp_pmu_line = []
        count = 0
        
diff = len(master_sensor_array) - len(master_pmu_array)
master_sensor_array = master_sensor_array[:-diff]

temp_final_array = []
final_array_item = []
counter = 0

while counter < len(master_sensor_array):
    final_array_item.append(master_sensor_array[counter])
    final_array_item.append(master_pmu_array[counter])
    temp_final_array.append(final_array_item)
    final_array_item = []
    counter += 1

final_array = []
position_final_array_line = []
for entry in temp_final_array:
    entry = entry[0] + entry[1]
    position_final_array_line.append(entry[4])
    position_final_array_line.append(sys.argv[1])
    entry[0] = int(entry[0])/1000
    entry[0] = str(entry[0])
    position_final_array_line.append(entry[0])
    entry[1] = int(entry[1])/1000
    entry[1] = str(entry[1])
    position_final_array_line.append(entry[1])
    entry[2] = int(entry[2])/1000
    entry[2] = str(entry[2])
    position_final_array_line.append(entry[2])
    entry[3] = int(entry[3])/1000
    entry[3] = str(entry[3])
    position_final_array_line.append(entry[3])
    position_final_array_line.append(entry[5])
    position_final_array_line.append(entry[6])
    position_final_array_line.append(entry[7])
    position_final_array_line.append(entry[8])
    position_final_array_line.append(entry[9])
    position_final_array_line.append(entry[10])
    final_array.append(position_final_array_line)
    position_final_array_line = [] 

with open('combined_data.txt', 'w') as f:
    for item in final_array:
        item = ", ".join(item)
        item = item.replace(", ", "\t")
        f.write("%s\n" % item)
f.close()
