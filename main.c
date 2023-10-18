#include "monty.h"
void (*f)(stack_t **stack, unsigned int line_number);
global_t vglo;
/**
 * free_vglo - frees the global variables
 *
 * Return: no return
 */
void free_vglo(void)
{
	free_dlistint(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}

/**
 * start_vglo - initializes the global variables
 *
 * @def_f: file descriptor
 * Return: no return
 */
void start_vglo(FILE *def_f)
{
	vglo.lifo = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = def_f;
	vglo.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @a_ac: argument count
 * @a_av: argument vector
 * Return: file struct
 */
FILE *check_input(int a_ac, char *a_av[])
{
	FILE *def_f;

	if (a_ac == 1 || a_ac > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	def_f = fopen(a_av[1], "r");

	if (def_f == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", a_av[1]);
		exit(EXIT_FAILURE);
	}

	return (def_f);
}

/**
 * main - Entry point
 *
 * @a_ac: argument count
 * @a_av: argument vector
 * Return: 0 on success
 */
int main(int a_ac, char *a_av[])
{
	FILE *def_f;
	size_t asz = 256;
	ssize_t num_l = 0;
	char *lines[2] = {NULL, NULL};

	def_f = check_input(a_ac, a_av);
	start_vglo(def_f);
	num_l = getline(&vglo.buffer, &asz, def_f);
	while (num_l != -1)
	{
		lines[0] = _strtoky(vglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_vglo();
				exit(EXIT_FAILURE);
			}
			vglo.arg = _strtoky(NULL, " \t\n");
			f(&vglo.head, vglo.cont);
		}
		num_l = getline(&vglo.buffer, &asz, def_f);
		vglo.cont++;
	}

	free_vglo();

	return (0);
}


