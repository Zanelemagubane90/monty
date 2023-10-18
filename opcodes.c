#include "monty.h"
/**
 * _push - pushes an element to the stack
 *
 * @hdll: head of the linked list
 * @linm: line number
 * Return: no return
 */
void _push(stack_t **hdll, unsigned int linm)
{
	int q, m;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", linm);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (m = 0; vglo.arg[m] != '\0'; m++)
	{
		if (!isdigit(vglo.arg[m]) && vglo.arg[m] != '-')
		{
			dprintf(2, "L%u: ", linm);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	q = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(hdll, q);
	else
		add_dnodeint_end(hdll, q);
}

/**
 * _pall - prints all values on the stack
 *
 * @hdll: head of the linked list
 * @linm: line numbers
 * Return: no return
 */
void _pall(stack_t **hdll, unsigned int linm)
{
	stack_t *fx;
	(void)linm;

	fx = *hdll;

	while (fx)
	{
		printf("%d\n", fx->n);
		fx = fx->next;
	}
}


/**
 * _pint - prints the value at the top of the stack
 *
 * @hdll: head of the linked list
 * @linm: line number
 * Return: no return
 */
void _pint(stack_t **hdll, unsigned int linm)
{
	(void)linm;

	if (*hdll == NULL)
	{
		dprintf(2, "L%u: ", linm);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*hdll)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @hdll: head of the linked list
 * @linm: line number
 * Return: no return
 */
void _pop(stack_t **hdll, unsigned int linm)
{
	stack_t *fx;

	if (hdll == NULL || *hdll == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", linm);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	fx = *hdll;
	*hdll = (*hdll)->next;
	free(fx);
}


/**
 * _swap - swaps the top two elements of the stack
 *
 * @hdll: head of the linked list
 * @linm: line number
 * Return: no return
 */
void _swap(stack_t **hdll, unsigned int linm)
{
	int b = 0;
	stack_t *fx = NULL;

	fx = *hdll;

	for (; fx != NULL; fx = fx->next, b++)
		;

	if (b < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", linm);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	fx = *hdll;
	*hdll = (*hdll)->next;
	fx->next = (*hdll)->next;
	fx->prev = *hdll;
	(*hdll)->next = fx;
	(*hdll)->prev = NULL;
}

