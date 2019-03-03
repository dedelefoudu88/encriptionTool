CC = g++
CFLAGS += -Wall -std=c++11
INCLUDES += $(shell pwd)/include
LIBS =
export

		
all : 
	$(MAKE) -C ./src

test : 
	$(MAKE) -C ./src
	$(MAKE) -C ./unitTest


clean :
	$(MAKE) -C unitTest clean
	$(MAKE) -C src clean


