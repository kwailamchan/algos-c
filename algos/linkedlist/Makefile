BUILD_DIR = _build

CC_FLAGS = -std=c99

all: clean build
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/a.out linkedlist_unsorted.c
	$(BUILD_DIR)/a.out

build:
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
