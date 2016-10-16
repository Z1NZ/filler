#include "filler.h"


int check_digit(char *tmp)
{
	while(*tmp != '\0')
	{
		ft_isdigit(*tmp);
		tmp++;
	}
	if (*tmp == '\0')
		return (1);
	else
		return (0);
}
