BUILD_DIR = _build

CC_FLAGS = -std=c99

all: clean build
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/binary_decimal binary_decimal.c
	$(BUILD_DIR)/binary_decimal
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/hamming_distance hamming_distance.c
	$(BUILD_DIR)/hamming_distance

build:
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
