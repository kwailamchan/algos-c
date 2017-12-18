BUILD_DIR = _build

CC = gcc
CC_FLAGS = -std=c99

all: clean build
	$(CC) $(CC_FLAGS) -o $(BUILD_DIR)/huffman huffman.c
	$(BUILD_DIR)/huffman

build:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
