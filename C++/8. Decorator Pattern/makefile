# make a makefile to run main.cpp
# Date: 2021/10/06

# Define the compiler we are using
CC = g++

# Define the flags we are using
CFLAGS = -Wall -std=c++17

# Define the target
TARGET = main

# Define the source files
SRC = main.cpp

# Define the object files
OBJ = $(SRC:.cpp=.o)

# Define the libraries
LIBS = -lncurses

# Define the rule to compile the source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Define the rule to link the object files
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LIBS)

# Define the rule to clean the object files
clean:
	rm -f $(OBJ) $(TARGET)