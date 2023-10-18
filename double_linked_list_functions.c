#include "monty.h"

/**
 *add_dnodeint_end - add a note at the end of the doubly link list
 *@hd_a: first position of linked list
 *@i: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **hd_a, const int i)
{
	stack_t *tmp_a, *a_x;

	if (hd_a == NULL)
		return (NULL);
	tmp_a = malloc(sizeof(stack_t));
	if (!tmp_a)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmp_a->n = i;
	/*Careful with the first time*/
	if (*hd_a == NULL)
	{
		tmp_a->next = *hd_a;
		tmp_a->prev = NULL;
		*hd_a = tmp_a;
		return (*hd_a);
	}
	a_x = *hd_a;
	while (a_x->next)
		a_x = a_x->next;
	tmp_a->next = a_x->next;
	tmp_a->prev = a_x;
	a_x->next = tmp_a;
	return (a_x->next);
}

/**
 *add_dnodeint - add a note at the begining of the doubly link list
 *@hd_a: first position of linked list
 *@i: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **hd_a, const int i)
{
	stack_t *tmp_a;

	if (hd_a == NULL)
		return (NULL);
	tmp_a = malloc(sizeof(stack_t));
	if (!tmp_a)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmp_a->n = i;
	/*Careful with the first time*/
	if (*hd_a == NULL)
	{
		tmp_a->next = *hd_a;
		tmp_a->prev = NULL;
		*hd_a = tmp_a;
		return (*hd_a);
	}
	(*hd_a)->prev = tmp_a;
	tmp_a->next = (*hd_a);
	tmp_a->prev = NULL;
	*hd_a = tmp_a;
	return (*hd_a);
}

/**
 * free_dlistint - frees the doubly linked list
 *
 * @hd_a: head of the list
 * Return: no return
 */
void free_dlistint(stack_t *hd_a)
{
	stack_t *tmp_a;

	while ((tmp_a = hd_a) != NULL)
	{
		hd_a = hd_a->next;
		free(tmp_a);
	}
}

