#include "filler.h"

void	ft_color(char **map)
{
	int i;
	int y;

	y = 0;
	ft_putstr_fd("\x1b[0;0H", 2);
	while (map[y])
	{
		i = 0;
		while (map[y][i] != '\0')
		{
			if (map[y][i] == 'O')
				ft_putstr_fd("\033[31m\033[41mO", 2);
			else if (map[y][i] == 'X')
				ft_putstr_fd("\033[33m\033[43mX", 2);
			else
				ft_putstr_fd("\033[30m.", 2);
			ft_putstr_fd("\033[0m", 2);
			i++;
		}
		ft_putstr_fd("\n", 2);
		y++;
	}
}
