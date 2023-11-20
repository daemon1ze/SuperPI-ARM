# Makefile for SuperPI with GMP on Apple ARM

# Compiler settings
CC = g++
CFLAGS = -O3 -march=armv8-a
LDFLAGS = -lpthread
GMP_PATH = $(shell brew --prefix gmp)

# Source and target files
SRC = superpi.cpp
TARGET = superpi

# Default rule
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -I$(GMP_PATH)/include -L$(GMP_PATH)/lib $(SRC) -lgmp $(LDFLAGS) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)

