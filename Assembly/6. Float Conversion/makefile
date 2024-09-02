# Variables
ASM = yasm
CC = gcc
ASMFLAGS = -f elf64
CFLAGS = -no-pie -lm

# Target executable
TARGET = test

# Source files
ASM_SRC = convertToFloat.asm
C_SRC = main.c

# Object files
OBJ = convertToFloat.o

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
