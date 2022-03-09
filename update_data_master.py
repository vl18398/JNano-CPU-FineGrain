master_bank = open('data_store.dat', 'a')
read_data = open('combined_data.txt', 'r')

for line in read_data:
    master_bank.write(line)

master_bank.close()
read_data.close()
