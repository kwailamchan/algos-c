/*
 * Huffman Coding (Greedy Algorithms)
 *
 *    huffman()
 *        +----- build_huffman_tree()
 *                     +------ create_and_build_minheap()
 *                                       +----- init_minheap()
 *                                       +----- create_minheap_node()
 *                                       +----- build_minheap()
 *                                                   +----- min_heapify()
 *                                                               +---- swap_minheap_node()
 */

#include <stdlib.h>

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


struct MinHeapNode * build_huffman_tree(char data[], int freq[], int size)
{
	struct MinHeapNode * left;
	struct MinHeapNode * right;
	struct MinHeapNode * top;

	struct MinHeap * min_heap = create_and_build_minheap(data, freq, size);	
}


void huffman(char data[], int freq[], int size)
{
	struct MinHeapNode * root = build_huffman_tree(data, freq, size);	
}


/* ---------------------------------------------------------------------------------------- */



/* ---------------------------------------------------------------------------------------- */


int main(void)
{
	char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = {5, 9, 12, 13, 16, 45};
	int size = sizeof(chars) / sizeof(chars[0]);
	huffman(chars, freq, size);
	return 0;
}
