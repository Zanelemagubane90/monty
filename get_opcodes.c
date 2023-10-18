#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc_a: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc_a))(stack_t **stack, unsigned int l_nums)
{
	instruction_t a_instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	int p;

	for (p = 0; a_instruct[p].opcode; p++)
	{
		if (_strcmp(a_instruct[p].opcode, opc_a) == 0)
			break;
	}

	return (a_instruct[p].f);
}

