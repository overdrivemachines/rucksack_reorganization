
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

rucksack_reorganization: rucksack_reorganization.o
	$(CC) $(CFLAGS) -o rucksack_reorganization rucksack_reorganization.o

rucksack_reorganization.o: rucksack_reorganization.cpp
	$(CC) $(CFLAGS) -c rucksack_reorganization.cpp

clean:
	rm -rf rucksack_reorganization rucksack_reorganization.o
