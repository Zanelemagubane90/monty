#include "monty.h"
/**
 * _strcmp - Function that compares two strings.
 * @str_o: type str compared
 * @str_t: type str compared
 * Return: 0 if str_o and str_t are equals.
 *         another value if they are different
 */
int _strcmp(char *str_o, char *str_t)
{
	int x;

	for (x = 0; str_o[x] == str_t[x] && str_o[x]; x++)
		;
	if (str_o[x] > str_t[x])
		return (1);
	if (str_o[x] < str_t[x])
		return (-1);
	return (0);
}

/**
 * _sch - search if a char is inside a string
 * @str_a: string to review
 * @str_f: char to find
 * Return: 1 if success 0 if not
 */
int _sch(char *str_a, char str_f)
{
	int acount = 0;

	while (str_a[acount] != '\0')
	{
		if (str_a[acount] == str_f)
		{
			break;
		}
		acount++;
	}
	if (str_a[acount] == str_f)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - function that cut a string into tokens depending of the delimit
 * @str_a: string to cut in parts
 * @dml: delimiters
 * Return: first partition
 */
char *_strtoky(char *str_a, char *dml)
{
	static char *ultm;
	int x = 0, j = 0;

	if (!str_a)
		str_a = ultm;
	while (str_a[x] != '\0')
	{
		if (_sch(dml, str_a[x]) == 0 && str_a[x + 1] == '\0')
		{
			ultm = str_a + x + 1;
			*ultm = '\0';
			str_a = str_a + j;
			return (str_a);
		}
		else if (_sch(dml, str_a[x]) == 0 && _sch(dml, str_a[x + 1]) == 0)
			x++;
		else if (_sch(dml, str_a[x]) == 0 && _sch(dml, str_a[x + 1]) == 1)
		{
			ultm = str_a + x + 1;
			*ultm = '\0';
			ultm++;
			str_a = str_a + j;
			return (str_a);
		}
		else if (_sch(dml, str_a[x]) == 1)
		{
			j++;
			x++;
		}
	}
	return (NULL);
}

