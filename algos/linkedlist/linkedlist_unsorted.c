/*
 * Write code to remove duplicates from an unsorted linked list.
 * Write code to reverse an unsorted linked list.
 * Write code to sort an unsorted linked list.
 */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node * next;
};


void list_append (struct Node * list, int data)
{
	struct Node * head = list;

	if (list == NULL)
		printf("Error: list does not exist.\n");

	while (head != NULL)
	{
		if (head->next == NULL)
		{
			struct Node * new = (struct Node*)malloc(sizeof(struct Node));
			new->data = data;
			new->next = NULL;
			head->next = new;
			return;
		}
		head = head->next; 
	}
}	


void list_traversal (struct Node * node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}


void list_free (struct Node * node)
{
	struct Node * head, * del;

	head = node;
	while (head != NULL)
	{	
		del = head;
		head = head->next;
		free (del);
	}
}


void list_remove_duplicates (struct Node * node)
{
	struct Node * head, * current, * duplicate;

	head = node;
	while (head != NULL && head->next != NULL)
	{
		current = head;
		while (current->next != NULL)
		{
			if (head->data == current->next->data)
			{
				duplicate = current->next;
				current->next = current->next->next;
				free (duplicate);
			}
			else
				current = current->next;
		}
		head = head->next;
	}
}


void list_reverse (struct Node ** list)
{
	struct Node * prev = NULL;
	struct Node * current = * list;
	struct Node * next;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	* list = prev;
}


void list_sort_bubble (struct Node * list)
{
	int temp;
	struct Node * head, * current;

	head = list;
	while (head != NULL)
	{
		current = head;
		while (current->next != NULL)
		{
			if (head->data > current->next->data)
			{
				temp = head->data;
				head->data = current->next->data;
				current->next->data = temp;
			}
			current = current->next;
		}
		head = head->next;
	}
}


void test_linkedlist_init (void)
{
	struct Node * head = (struct Node*)malloc(sizeof(struct Node));
	head->data = 1;
	head->next = NULL;
	list_append(head, 1);
	list_append(head, 2);
	list_append(head, 3);
	list_append(head, 6);
	list_append(head, 4);
	list_append(head, 1);
	list_append(head, 6);

	printf("list (origin): "); list_traversal(head);
	list_remove_duplicates(head);
	printf("list (duplicates removed): "); list_traversal(head);
	list_reverse(&head);
	printf("list (reverse): "); list_traversal(head);
	list_sort_bubble(head);
	printf("list (sort): "); list_traversal(head);

	list_free (head);
}


int main(void)
{
	test_linkedlist_init();
}
