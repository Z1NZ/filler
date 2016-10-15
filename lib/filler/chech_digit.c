#include "filler.h"


int check_digit(char *tmp)
{
	while(tmp)
	{
		ft_isdigit(*tmp);
		tmp++;
	}
	if (tmp == '\0')
		return (1);
	else
		return (0);
}
