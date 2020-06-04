#############################################################################
# Makefile for building: Multi-axis-Control
# Generated on: 2013-10-14
# Template: app
#############################################################################

# Defining the compiler:
CC = g++
PRJ_ROOT = $(shell pwd)

# Defining compiler flags:
CFLAGS = -O0 -Wall -std=c++11 -Wall 

# Defining linker flags:
LFLAGS = -lm -lrt -lc -Wall  -L$(PRJ_ROOT)/libs -lnrlab02 -lpthread

# Defining Include flags:
INC = -I./include

# Defining Source file flags:
VPATH = ../src 


# The default rule - compiling our main program:
all:	 
	make clean
	mkdir -p bin
	$(CC) -o ./bin/motor_rpm ./samples/motor_rpm.cpp $(INC) $(CFLAGS) $(LFLAGS)
	$(CC) -o ./bin/vel_cmd ./samples/vel_cmd.cpp $(INC) $(CFLAGS) $(LFLAGS)
	$(CC) -o ./bin/sensor_read ./samples/sensor_read.cpp $(INC) $(CFLAGS) $(LFLAGS)
	$(CC) -o ./bin/ecat_state ./samples/ecat_state.cpp $(INC) $(CFLAGS) $(LFLAGS)
	
	
# Removing the executable and the object files
clean: 
	rm -rf ./bin/*
	echo clean: make complete
