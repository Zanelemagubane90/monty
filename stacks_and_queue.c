#include "monty.h"

/**
 * _queue - sets format of data to queue(FIFI/LILO)
 * @holl: head of linked list
 * @linm: line number
 */
void _queue(stack_t **holl, unsigned int linm)
{
	(void)holl;
	(void)linm;

	vglo.lifo = 0;
}

/**
 * _stack - sets format of data to stack (LIFO/FILO)
 * @holl: linked list head
 * @linm: line number
 */
void _stack(stack_t **holl, unsigned int linm)
{
	(void)holl;
	(void)linm;

	vglo.lifo = 1;
}

