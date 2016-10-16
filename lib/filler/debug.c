#include "filler.h"

void	ft_print_tab(char **tab)
{
	while(*tab)
	{
		printf("%s\n", *tab);
		tab++;
	}
}
void	debug(t_data *data)
{
	printf("status	= [%d]\n", data->status);
	printf("map x	= [%d]\n", data->x);
	printf("map y	= [%d]\n", data->y);
	printf("curent	= [%d]\n", data->curent);
	printf("map x[%d] y[%d]:\n",  data->x, data->y);
	ft_print_tab(data->map);
	printf("piece x	= [%d]\n", data->piece.x);
	printf("piece y	= [%d]\n", data->piece.y);
	printf("piece curent = [%d]\n", data->piece.curent);
	printf("piece x[%d] y[%d]:\n",  data->piece.x, data->piece.y);
	ft_print_tab(data->piece.piece);
}