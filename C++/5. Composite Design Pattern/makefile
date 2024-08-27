# write makefile for main.cpp


# Variables
CC = g++
CFLAGS = -c -Wall
LFLAGS = -Wall
OBJS = main.o
TARGET = main

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -f $(OBJS) $(TARGET)