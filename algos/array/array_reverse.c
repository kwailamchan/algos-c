/*
 * to reverse an array
 */

#include <stdio.h>


void array_reverse (int array[], int start, int end)
{
	int temp;
	while (end > start)
	{
		temp = array[end];
		array[end] = array[start];
		array[start] = temp;

		start++;
		end--;
	}	
}


void array_print (int array[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}


int main()
{
	int array[] = {1, 2, 3, 3, 4, 5};
	int size = sizeof(array) / sizeof(array[0]);
	printf("array (original): "); array_print(array, size);
	array_reverse(array, 0, size-1);
	printf("array (reverse): "); array_print(array, size);

	return 0;
}
