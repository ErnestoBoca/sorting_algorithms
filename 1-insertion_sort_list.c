#include "sort.h"
/**
 * swapp - swapps two nodes and updates the head of the list if necessary
 * @node1: the first node
 * @node2: the second node
 * @head: the head of the list
 * Return: nothing
*/
void swapp(listint_t *node1, listint_t *node2, listint_t **head)
{
	if (node1 == NULL || node2 == NULL)
		return;

	node1->next = node2->next;
	node2->next = node1;
	node2->prev = node1->prev;
	node1->prev = node2;
	if (node1->next != NULL)
		node1->next->prev = node1;
	if (node2->prev != NULL)
		node2->prev->next = node2;
	else
		*head = node2;
}

/**
 * insertion_sort_list -  sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @head: the head of the list
 * Return: nothing
*/
void insertion_sort_list(listint_t **head)
{
	listint_t *actual, *temp;
	int swapped;

	if (*head == NULL)
		return;

	actual = *head;
	while (actual->next != NULL)
	{
		swapped = 0;
		temp = actual->next;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swapp(temp->prev, temp, head);
				print_list(*head);
				swapped = 1;
			} else
				break;
		}
		if (!swapped)
			actual = actual->next;
	}

}
