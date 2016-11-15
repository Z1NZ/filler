/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commando_para.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 07:00:44 by srabah            #+#    #+#             */
/*   Updated: 2016/11/11 14:02:29 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		claymore(t_data *data, int pos_x, int pos_y, char min, char maj, int save_x, int save_y)
{
	char	**tmp;
	char	**tab;
	int		x;
	int		y;
	int		touch;

	touch = 0;
	y = 0;
	tmp = data->piece.piece;
	tab = data->map;
	while ((y + save_y) < data->piece.y && pos_y + y < data->y)
	{
		x = 0;
		while ((x + save_x) < data->piece.x && (pos_x + x) < data->x)
		{
			if (tmp[y + save_y][x + save_x] == tab[pos_y + y][pos_x + x] 
				|| ((tmp[y + save_y][x + save_x] == '*') && tab[pos_y + y][pos_x + x] == '.'))
				++x;
			else if ((tab[pos_y + y][pos_x + x] == maj || tab[pos_y + y][pos_x + x] == min) &&
				(tmp[y + save_y][x + save_x] == '*'))
			{
				touch++;
				++x;
			}
			else
				return (0);
		}
		++y;
	}
	if (touch == 1)
		return (1);
	// if (pos_y == 0)
	// fprintf(stderr, "pos_y=[%d]	pos_x=[%d]	save_x=[%d]	save_y=[%d]	touch=[%d]\n", pos_y, pos_x, save_x, save_y, touch);
	return (0);
}

void	supervision(t_data *data, char maj, char min, int save_x, int save_y)
{
	char	**tmp;
	int		x;
	int		y;

	y = 0;
	tmp = data->map;
	while (tmp[y])
	{
		x = 0;
		while (tmp[y][x] && x < (data->x - 1))
		{
			if (claymore(data, x, y, min, maj, save_x, save_y) == 1)
				add_pos(data, x - save_x, y - save_y);
			++x;
		}
		++y;
	}
}


void	ft_super_wod(t_data *data)
{
	int y;
	int save_y;
	int x;
	int save_x;

	save_x = INT_MAX;
	y = -1;
	while(ft_strstr(data->piece.piece[++y],"*") == NULL)
		;
	save_y = y;
	--y;
	while(data->piece.piece[++y])
	{
		x = -1;
		while(data->piece.piece[y][++x])
		{
			if (data->piece.piece[y][x] == '*' && x < save_x)
				save_x = x;
		}
	}
	if (CHECK_BIT(data->status, OPT_PLAYER1))
		supervision(data, 'O', 'o', save_x, save_y);
	else
		supervision(data, 'X', 'x', save_x, save_y);
}

void	commando_para(t_data *data)
{
	ft_super_wod(data);
	if (data->pos)
	{
		ft_putnbr(data->pos->y);
		write(1, " ", 1);
		ft_putnbr(data->pos->x);
		write(1, "\n", 1);
	}
	else
		write(1, "0 0\n", 4);
	ft_free(data);
}
