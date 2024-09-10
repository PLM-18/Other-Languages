CC = g++ 
CFLAGS = -Wall -Werror
LFLAGS = -static
TARGET = main
OBJECTS = main.o

# Linking all the object code:
all: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(TARGET)

# Dependencies:
main.o: main.c

# Compilation rule:
%.o: %.cpp
	$(CC) $< $(CFLAGS) -c -o $@

# Custom commands:
clean:
	rm -f $(TARGET) $(OBJECTS)

run:
	./$(TARGET)