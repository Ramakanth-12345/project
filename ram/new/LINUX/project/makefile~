CC=gcc
CFLAGS=-Wall
INCPATH=-Iincludes
EXECUTABLE=programs
OBJECTS_DIR=object
SRC_DIR=source

C_SOURCES=$(wildcard $(SRC_DIR)/*.c)
#SRC_DIR=source

OBJECTS =$(C_SOURCES:$(SRC_DIR)/%.c=$(OBJECTS_DIR)/%.o)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) -Wall -o $(EXECUTABLE) $(OBJECTS)

$(OBJECTS):$(OBJECTS_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) -c $(INCPATH) -Wall -o $@ $< 

clean: 
		rm -rf $(EXECUTABLE) $(OBJECTS)
