#include "filler.h"

void	tab_free(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		// ft_putstr_fd("[", 2);
		// ft_putstr_fd(str[i], 2);
		// ft_putstr_fd("]\n", 2);

		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}