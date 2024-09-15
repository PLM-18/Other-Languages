# Makefile

# Compiler and assembler settings
CC = gcc
ASM = yasm
ASMFLAGS = -f elf32
CFLAGS = -m32

# Output executable
TARGET = program

# Source files
ASM_SRC = adding.asm
C_SRC = main.c

# Object files
ASM_OBJ = adding.o
C_OBJ = main.o

# Rule to build the target executable
$(TARGET): $(C_OBJ) $(ASM_OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(C_OBJ) $(ASM_OBJ)

# Rule to assemble the assembly source file
$(ASM_OBJ): $(ASM_SRC)
	$(ASM) $(ASMFLAGS) -o $(ASM_OBJ) $(ASM_SRC)

# Rule to compile the C source file
$(C_OBJ): $(C_SRC)
	$(CC) $(CFLAGS) -c $(C_SRC)

# Clean up object files and the executable
clean:
	rm -f $(TARGET) $(C_OBJ) $(ASM_OBJ)
