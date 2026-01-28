#include "push_swap.h"

int num_bytes(char *str)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
		if ((*str >= 0 && *str <= 9) || *str == '-')
		{
			*str++;
			count++;
		}
		else if (*str == '\t' || *str == ' ')
			*str++;
	}
	return (count);
}


char **split(char *str)
{
	char    **newstr;
	int     i;
	int     j;

	i = 0;
	newstr = malloc(num_bytes(*str) * 1);
	if (newstr == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == ' ')
			*str++;
		i = 0;
		while ((*str >= '0' && *str <= '9') || *str == '-')
		{
			newstr[j][i] = *str;
			str++;
			i++;
		}
		newstr[j][i] = '\0';
		j++;
	}
	return (newstr);
}