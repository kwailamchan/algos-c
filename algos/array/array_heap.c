/*
 * Remove duplicates from an unsorted array.
 */

#include <stdio.h>
#include <stdlib.h>

#define N 10

void array_init (int * A)
{
	for (int i = 0; i < N; i += 2)
	{
		A[i] = i;
		A[i+1] = i;
	}
}


void array_traversal (int * A)
{
	for (int i = 0; i < N; ++i)
		printf("%d ", A[i]);
	printf("\n");
}


void array_remove_duplicates (int * A)
{
	int * temp = (int*)malloc(N*sizeof(int));
	unsigned int counter = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i+1; j < N; ++j)
		{
			if (A[i] != A[j]) temp[counter] = A[i];
			counter++;
		}	
	}
	
	for (int i = 0; i < counter; ++i)
		A[i] = temp[i];
	free (temp);
}


int main(void)
{
	int * A = (int*)malloc(N*sizeof(int));
	array_init(A); array_traversal(A);
	array_remove_duplicates(A); array_traversal(A);

	free (A);

	return 0;
}
