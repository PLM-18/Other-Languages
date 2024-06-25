SRC_DIR = src
BUILD_DIR = build
MAIN_CLASS = App

# List of Java source files
SOURCES = $(wildcard $(SRC_DIR)/*.java)

# List of Java class files to compile
CLASSES = $(SOURCES:$(SRC_DIR)/%.java=$(BUILD_DIR)/%.class)

# Compiler and options
JAVAC = javac
JAVAFLAGS = -d $(BUILD_DIR)

.PHONY: all run clean

all: $(CLASSES)

$(BUILD_DIR)/%.class: $(SRC_DIR)/%.java
	$(JAVAC) $(JAVAFLAGS) $<

run:
	java -cp $(BUILD_DIR) $(MAIN_CLASS)

clean:
	rm -rf $(BUILD_DIR)/*.class
