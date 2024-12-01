# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11
# OpenSSL libraries
LIBS = -lssl -lcrypto

# Source directory
SRC_DIR = src
# Bin directory for object files and executables
BIN_DIR = bin

# Create bin directory if it doesn't exist
$(shell mkdir -p $(BIN_DIR))

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRCS))

# Executables
EXECUTABLES = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%, $(SRCS))

# Main target
all: $(EXECUTABLES)

# Compile source files into object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executables
$(EXECUTABLES): $(OBJS)
	$(CC) $(CFLAGS) $@.o -o $@ $(LIBS)

# Clean up
clean:
	rm -f $(OBJS) $(EXECUTABLES)
