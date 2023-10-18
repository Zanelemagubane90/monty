#include "monty.h"

/**
 * _rotl - rotates 1st element to the bottom and 2nd to the top
 * @llhd: linked list head
 * @linm: line nummber
 */
void _rotl(stack_t **llhd, unsigned int linm)
{
	stack_t *adc = NULL;
	stack_t *abx = NULL;
	(void)linm;

	if (*llhd == NULL)
		return;

	if ((*llhd)->next == NULL)
		return;

	adc = (*llhd)->next;
	abx = *llhd;

	for (; abx->next != NULL; abx = abx->next)
		;

	adc->prev = NULL;
	abx->next = *llhd;
	(*llhd)->next = NULL;
	(*llhd)->prev = abx;
	*llhd = adc;
}

/**
 * _rotr - reverse stack
 * @llhd: linked list head
 * @linm: line number
 */
void _rotr(stack_t **llhd, unsigned int linm)
{
	stack_t *fx = NULL;
	(void)linm;

	if (*llhd == NULL)
		return;

	if ((*llhd)->next == NULL)
		return;

	fx = *llhd;

	for (; fx->next != NULL; fx = fx->next)
		;

	fx->prev->next = NULL;
	fx->next = *llhd;
	fx->prev = NULL;
	(*llhd)->prev = fx;
	*llhd = fx;
}


