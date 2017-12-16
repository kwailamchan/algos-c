BUILD_DIR = _build

CC_FLAGS = -std=c99


all: clean build
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/array_stack array_stack.c
	$(BUILD_DIR)/array_stack
	gcc $(CC_FLAGS) -o $(BUILD_DIR)/array_heap array_heap.c
	$(BUILD_DIR)/array_heap

build:
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
