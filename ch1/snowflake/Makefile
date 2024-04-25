# Compiler and linker configurations
CC = gcc
CFLAGS = -Wall -Iheader -g
# LDFLAGS = 

# Directories
SRC_DIR = source
HDR_DIR = header
BUILD_DIR = build

# Find all source files in the source directory, replace directory with build directory for objects
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGET = $(BUILD_DIR)/snowflake

.PHONY: all clean

# Default target
all: $(TARGET)

# Linking the executable from the object files
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compiling source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)
