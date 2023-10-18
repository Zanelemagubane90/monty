#include "monty.h"

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 * @hoft: head of the linked list
 * @linm: line number;
 * Return: no return
 * info:The result is stored in 2nd value node from the top
 * and top value removed.
 */

void _mod(stack_t **hoft, unsigned int linm)
{
	int q = 0;
	stack_t *xu = NULL;

	xu = *hoft;

	for (; xu != NULL; xu = xu->next, q++)
		;

	if (q < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", linm);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*hoft)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", linm);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	xu = (*hoft)->next;
	xu->n %= (*hoft)->n;
	_pop(hoft, linm);
}
/**
 * _pstr - prints the string of the stack
 *
 * @hoft: head of the linked list
 * @linm: line number;
 * Return: no return
 */
void _pstr(stack_t **hoft, unsigned int linm)
{
	stack_t *xu;
	(void)linm;

	xu = *hoft;

	while (xu && xu->n > 0 && xu->n < 128)
	{
		printf("%c", xu->n);
		xu = xu->next;
	}

	printf("\n");
}
/**
 * _pchar - print the char value of the first element
 *
 * @hoft: head of the linked list
 * @linm: line number;
 * Return: no return
 */
void _pchar(stack_t **hoft, unsigned int linm)
{
	if (hoft == NULL || *hoft == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", linm);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*hoft)->n < 0 || (*hoft)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", linm);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*hoft)->n);
}

