# Variables
ASM = yasm
CC = g++
ASMFLAGS = -f elf64
CFLAGS = -no-pie -lm

# Target executable
TARGET = test

# Source files
ASM_SRC = functions.asm
C_SRC = main.cpp

# Object files
OBJ = functions.o

# Default target
all: $(TARGET)

# Compile assembly files to object files
$(OBJ): $(ASM_SRC)
	$(ASM) $(ASMFLAGS) -o $(OBJ) $(ASM_SRC)

# Compile and link C and assembly object files
$(TARGET): $(C_SRC) $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(C_SRC) $(OBJ)

# Clean up generated files
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
