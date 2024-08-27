# Makefile

# Compiler and assembler
CC = gcc
ASM = yasm

# Flags
CFLAGS = -c
ASMFLAGS = -f elf64

# Targets and object files
TARGET = main
C_OBJ = main.o
ASM_OBJ = xor.o

# Default target
all: $(TARGET)

# Rule to build the C object file
$(C_OBJ): main.c
	$(CC) $(CFLAGS) main.c -o $(C_OBJ)

# Rule to build the assembly object file
$(ASM_OBJ): xor.asm
	$(ASM) $(ASMFLAGS) xor.asm -o $(ASM_OBJ)

# Rule to link the object files into the final executable
$(TARGET): $(C_OBJ) $(ASM_OBJ)
	$(CC) $(C_OBJ) $(ASM_OBJ) -o $(TARGET)

# Clean up generated files
clean:
	rm -f $(C_OBJ) $(ASM_OBJ) $(TARGET)
