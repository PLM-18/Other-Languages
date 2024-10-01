# Define the compiler we are using
CC = gcc

# Define the flags we are using
CFLAGS = -std=c17 -v  # Added -Wall for warnings and -v for verbosity
LDFLAGS = -v  # Verbose linking

# Define the target
TARGET = main

# Define the source files
SRC = main.c

# Define the object files
OBJ = $(SRC:.c=.o)

# Define the libraries
LIBS = -lncurses

# Define the rule to compile the source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

# Define the rule to link the object files
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $(TARGET) $(LIBS)

# Define the rule to generate assembly files
%.s: %.c
	$(CC) $(CFLAGS) -S -masm=intel $< -o $@

# Define the rule to clean the object and assembly files
clean:
	rm -f $(OBJ) $(TARGET) *.s
