BUILD_DIR = _build

CC_FLAGS = -std=c99

all: clean build
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/string_reverse string_reverse.c
	$(BUILD_DIR)/string_reverse

build:
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
