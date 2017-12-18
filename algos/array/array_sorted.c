/*
 * To remove duplicates from a sorted array
 */

#include <stdio.h>
#include <stdlib.h>

int get_duplicates_size (int * array, int size)
{
	int n = 0;
	for (int i = 0; i < size - 1; ++i)
		if (array[i] == array[i+1]) n++;

	return size - n;
}


void array_remove_duplicates(int * array_clean, int n, int * array, int size)
{
	int counter = 0;
	for (int i = 0; i < size; ++i)
	{
		if (array[i] != array[i+1])
			array_clean[counter++] = array[i];
	}
}


void array_print(int * array, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}


int main(void)
{
	int array[] = {1, 1, 2, 3, 3, 3, 4};
	int size = sizeof(array) / sizeof(array[0]);
	printf("array (origin): "); array_print(&array, size);
	int n = get_duplicates_size(array, size);
	int * array_clean = (int *)malloc(n*sizeof(int));
	array_remove_duplicates(array_clean, n, array, size);
	printf("array (remove duplicates): "); array_print(array_clean, n);
	free (array_clean);
	return 0;
}
