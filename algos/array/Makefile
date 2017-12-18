BUILD_DIR = _build

CC_FLAGS = -std=c99


all: clean build
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/array_reverse array_reverse.c
	$(BUILD_DIR)/array_reverse
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/array_sorted array_sorted.c
	$(BUILD_DIR)/array_sorted
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/array_unsorted array_unsorted.c
	$(BUILD_DIR)/array_unsorted

build:
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
