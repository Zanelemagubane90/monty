#include "monty.h"

/**
 * _add - Adds the top two values of a stack_t linked list.
 * @lnk_a: hdn of the linked list
 * @line_num: line number
 * Description: The result is stored in the second value node
 * from the top and the top value  is removed.
 */
void _add(stack_t **lnk_a, unsigned int line_num)
{
	int q = 0;
	stack_t *aux = NULL;

	aux = *lnk_a;

	for (; aux != NULL; aux = aux->next, q++)
		;

	if (q < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*lnk_a)->next;
	aux->n += (*lnk_a)->n;
	_pop(lnk_a, line_num);
}

/**
 * _nop - doesn't do anything
 * @lnk_a: linked list hdn
 * @line_num: line number
 */
void _nop(stack_t **lnk_a, unsigned int line_num)
{
	(void)lnk_a;
	(void)line_num;
}
/**
 * _sub - Subtracts 2nd value from the top of stack_t linked list by top value.
 * @hdn: the hdn node
 * @line_num: the line number
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */

void _sub(stack_t **hdn, unsigned int line_num)
{
	int q = 0;
	stack_t *cnt;

	cnt = *hdn;

	for (; cnt != NULL; cnt = cnt->next, q++)
		;

	if (q < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	cnt = (*hdn)->next;
	cnt->n -= (*hdn)->n;
	_pop(hdn, line_num);
}

/**
 *_div -Divides 2nd value from the top of stack_t linkedlist by the top value.
 * @lnk_a: hdn of the linked list
 * @line_num: line number;
 * Return: no return
 */

void _div(stack_t **lnk_a, unsigned int line_num)
{
	int q = 0;
	stack_t *aux = NULL;

	aux = *lnk_a;

	for (; aux != NULL; aux = aux->next, q++)
		;

	if (q < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*lnk_a)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*lnk_a)->next;
	aux->n /= (*lnk_a)->n;
	_pop(lnk_a, line_num);
}

/**
 *_mul -Multiplies 2nd value from the top of stack_t linked list by top value.
 * @hdn: the hdn node
 * @line_num: the line number
 * info:The result is stored in the 2nd value node
 * from the top and top value removed.
 */

void _mul(stack_t **hdn, unsigned int line_num)
{
	int q = 0;
	stack_t *cnt;

	cnt = *hdn;

	for (; cnt != NULL; cnt = cnt->next, q++)
		;

	if (q < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_num);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	cnt = (*hdn)->next;
	cnt->n *= (*hdn)->n;
	_pop(hdn, line_num);
}

