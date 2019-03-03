CC = g++
##CFLAGS = ${CFLAGS}
OBJ = obj
SOURCE_FILES = $(wildcard *.c)
SOURCE_FILES += $(wildcard *.cpp)
SOURCE_FILES += $(wildcard *.cc)
OBJ_FILES+=$(addprefix $(OBJ)/, $(SOURCE_FILES:.cpp=.o))
export

EXEC_NAME= printTab

all: $(OBJ_FILES)
	@echo "Nothing to be done"
#	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)
#	@echo "$(EXEC_NAME) creat"

$(OBJ_FILES) : $(SOURCE_FILES)
	@echo "compile $(OBJ_FILES)"
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $(OBJ_FILES) -c $(SOURCE_FILES)
	
%.o: %.cpp
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

%.o: %.cc
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

%.o: %.c
	@echo "Compiling $<"
	gcc $(CFLAGS) -I $(INCLUDES) -o $@ -c $<


clean:
	rm -f $(EXEC_NAME)
	rm -f $(OBJ_FILES)
