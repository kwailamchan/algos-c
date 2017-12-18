/*
 * Huffman Coding (Greedy Algorithms)
 *
 *    huffman()
 *        +----- build_huffman_tree()
 *                     +
 *                     +------ create_and_build_minheap()
 *                     +                  +----- init_minheap()
 *                     +                  +----- create_minheap_node()
 *                     +                  +----- build_minheap()
 *                     +                              +----- min_heapify()
 *                     +                                          +---- swap_minheap_node()
 *                     +------ is_size_one()
 *                     +------ extract_min()
 *                     +------ insert_minheap()
 *
 *    print_tree()
 *         +---- print_array()
 *         +---- is_leaf()
 */

#include <stdio.h>
#include <stdlib.h>

#define TREE_MAX_HEIGHT 100


struct MinHeapNode
{
	char data;
	unsigned freq;
	struct MinHeapNode * left;
	struct MinHeapNode * right;
};


struct MinHeap
{
	unsigned size;
	unsigned capacity;
	struct MinHeapNode ** array;	
};


/* ---------------------------------------------------------------------------------------- */


struct MinHeap * init_minheap(unsigned capacity)
{
	struct MinHeap * minheap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minheap->size = 0;
	minheap->capacity = capacity;
	minheap->array = (struct MinHeapNode**)malloc(minheap->capacity*sizeof(struct MinHeapNode*));
	return minheap;
}


struct MinHeapNode * create_minheap_node (char data, unsigned freq)
{
	struct MinHeapNode * node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	node->data = data;
	node->freq = freq;
	node->left = NULL;
	node->right = NULL;

	return node;
}


void swap_minheap_node(struct MinHeapNode ** a, struct MinHeapNode ** b)
{
	struct MinHeapNode * t = * a;
	* a = * b;
	* b = t;
}


void min_heapify(struct MinHeap * minheap, int idx)
{
	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minheap->size && minheap->array[left]->freq < minheap->array[smallest]->freq)
		smallest = left;

	if (right < minheap->size && minheap->array[right]->freq < minheap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx)
	{
		swap_minheap_node(&minheap->array[smallest], &minheap->array[idx]);
		min_heapify(minheap, smallest);
	}
}


void build_minheap(struct MinHeap * minheap)
{
	int n = minheap->size - 1;
	for (int i = (n - 1) / 2; i >= 0; --i)
		min_heapify(minheap, i);
}


struct MinHeap * create_and_build_minheap(char data[], int freq[], int size)
{
	struct MinHeap * minheap = init_minheap(size);
	for (int i = 0; i < size; ++i)
		minheap->array[i] = create_minheap_node(data[i], freq[i]);
	minheap->size = size;
	
	build_minheap(minheap);

	return minheap;
}


int is_size_one(struct MinHeap * minheap)
{
	return (minheap->size == 1);
}


struct MinHeapNode * extract_min(struct MinHeap * minheap)
{
	struct MinHeapNode * node = minheap->array[0];
	minheap->array[0] = minheap->array[minheap->size - 1];
	--minheap->size;
	min_heapify(minheap, 0);
	return node;
}


void insert_minheap(struct MinHeap * minheap, struct MinHeapNode * node)
{
	++minheap->size;
	int i = minheap->size - 1;
	while (i && node->freq < minheap->array[(i - 1) / 2]->freq)
	{
		minheap->array[i] = minheap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minheap->array[i] = node;
}


struct MinHeapNode * build_huffman_tree(char data[], int freq[], int size)
{
	struct MinHeapNode * left;
	struct MinHeapNode * right;
	struct MinHeapNode * top;

	struct MinHeap * minheap = create_and_build_minheap(data, freq, size);
	while (!is_size_one(minheap))
	{
		left = extract_min(minheap);
		right = extract_min(minheap);

		top = create_minheap_node('$', left->freq + right->freq);
		top->left = left;
		top->right = right;	
		insert_minheap(minheap, top);
	}

	return extract_min(minheap);
}


int is_leaf(struct MinHeapNode * root)
{
	return !(root->left) && !(root->right);
}


void print_array(int array[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d", array[i]);
	printf("\n");
}


void print_tree(struct MinHeapNode * root, int array[], int top)
{
	if (root->left)
	{
		array[top] = 0;
		print_tree(root->left, array, top+1);
	}

	if (root->right)
	{
		array[top] = 1;
		print_tree(root->right, array, top+1);
	}

	if (is_leaf(root))
	{
		printf("%c: ", root->data);
		print_array(array, top);
	}
}


void huffman(char data[], int freq[], int size)
{
	struct MinHeapNode * root = build_huffman_tree(data, freq, size);	

	int array[TREE_MAX_HEIGHT];
	int top = 0;
	print_tree(root, array, top);
}


/* ---------------------------------------------------------------------------------------- */


int main(void)
{
	char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};
	int size = sizeof(chars) / sizeof(chars[0]);
	huffman(chars, freq, size);
	return 0;
}
