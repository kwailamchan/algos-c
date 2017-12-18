/*
 * To remove duplicates from an unsorted array
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int get_duplicates_size (int * array, int size)
{
	int n = 0;
	bool is_duplicated = false;
	for (int i = 0; i < size - 1; ++i)
	{
		is_duplicated = false;
		for (int j = i+1; j < size - 1; ++j)
			if (array[i] == array[j]) is_duplicated = true;
		if (is_duplicated == false) n++;
	}

	return n;
}


void array_remove_duplicates(int * array_clean, int n, int * array, int size)
{
	int counter = 0;
	bool is_duplicated = false;	
	for (int i = 0; i < size; ++i)
	{
		is_duplicated = false;
		for (int j = i+1; j < size; ++j)
			if (array[i] == array[j]) is_duplicated = true;

		if (is_duplicated == false) array_clean[counter++] = array[i]; 
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
	int array[] = {1, 3, 5, 1, 3, 5, 6, 7, 5, 7};
	int size = sizeof(array) / sizeof(array[0]);
	printf("array (origin): "); array_print(&array, size);
	int n = get_duplicates_size(array, size);
	int * array_clean = (int *)malloc(n*sizeof(int));
	array_remove_duplicates(array_clean, n, array, size);
	printf("array (remove duplicates): "); array_print(array_clean, n);
	free (array_clean);
	return 0;
}
