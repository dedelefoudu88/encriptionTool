CC = g++
CFLAGS +=
INCLUDES += $(shell pwd)/include 
#INCLUDES += $(shell pwd)/../tools/include
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


