CC = g++
CFLAGS += -Wall -std=c++11
INCLUDES += $(shell pwd)/tools/include
LIBS =
export
FOLDERS = ./tools
FOLDERS += ./Sbox

all : 
	$(MAKE) -C ./tools
	$(MAKE) -C ./Sbox test
	

Sbox :
	$(MAKE) -C ./tools
	$(MAKE) -C ./Sbox test
	
tools : 
	$(MAKE) -C ./tools test
	


clean :
	$(MAKE) -C ./tools clean
	$(MAKE) -C ./Mbox clean
	$(MAKE) -C ./Permutation clean
	$(MAKE) -C ./Sbox clean
	$(MAKE) -C ./SPN clean
