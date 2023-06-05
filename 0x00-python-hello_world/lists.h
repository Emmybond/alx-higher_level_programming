#ifndef lists_h
#define lists_h

#include <stdlib.h>

/**
 * struct listint_s - It represents singly linked list
 * @n: It represents integer
 * @next: It points to the next node
 *
 * Description: This describes singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
void free_listint(listint_t *head);
int check_cycle(listint_t *list);

#endif /* lists_h */


