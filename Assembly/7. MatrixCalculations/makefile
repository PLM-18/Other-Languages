# Compiler
CC = gcc

# Assembler
AS = nasm

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Assembler flags
ASFLAGS = -f elf64

# Target executable
TARGET = program

# Object files
OBJS = allocateMatrix.o main.o

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to assemble allocateMatrix.asm
allocateMatrix.o: allocateMatrix.asm
	$(AS) $(ASFLAGS) -o allocateMatrix.o allocateMatrix.asm

# Rule to compile main.c
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(OBJS)