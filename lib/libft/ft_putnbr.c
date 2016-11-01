
#include "filler.h"

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(int n)
{
	unsigned int	u_nbr;

	u_nbr = n;
	if (n < 0)
	{
		ft_putchar('-');
		u_nbr = -n;
	}
	if (u_nbr / 10)
		ft_putnbr(u_nbr / 10);
	ft_putchar(u_nbr % 10 + '0');
}