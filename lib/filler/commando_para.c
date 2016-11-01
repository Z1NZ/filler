/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commando_para.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 07:00:44 by srabah            #+#    #+#             */
/*   Updated: 2016/10/26 07:00:45 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		claymore(t_data *data, int pos_x, int pos_y, char min, char maj)
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
	while (tmp[y] && tab[pos_y + y])
	{
		x = 0;
		while (y < data->piece.y && tmp[y][x] && tab[pos_y + y][pos_x + x])
		{
			if (tmp[y][x] == tab[pos_y + y][pos_x + x] || ((tmp[y][x] == '*') && tab[pos_y + y][pos_x + x] == '.'))
				++x;
			else if ((tab[pos_y + y][pos_x + x] == maj || tab[pos_y + y][pos_x + x] == min) && (tmp[y][x] == '*'))
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
	return (0);
}

void	supervision(t_data *data, char maj, char min)
{
	char	**tmp;
	int		x;
	int		y;

	y = 0;
	tmp = data->map;
	while (tmp[y])
	{
		x = 0;
		while (tmp[y][x])
		{
			if (claymore(data, x, y, min, maj) == 1)
				add_pos(data, x, y);
			++x;
		}
		++y;
	}
}

void	ft_finisher(t_data *data, int s_y, int s_x, int start)
{
	char	**tab;
	int		x;
	int		y;
	int		super;

	x = 0;
	y = 0;
	tab = ft_memalloc(sizeof(char *) * s_y);
	super = 0;
	while (y < data->piece.y && data->piece.piece[y])
	{
		x = 0;
		while (data->piece.piece[y][x] != '\0' && data->piece.piece[y][x] == '.')
			x++;
		if (data->piece.piece[y][x] != '\0')
		{
			tab[super] = ft_strdup(ft_strsub(data->piece.piece[y], start, s_x));
			++super;
		}
		y++;
	}
	data->piece.y = s_y;
	data->piece.x = s_x;
	ft_memdel((void**)&data->piece.piece);
	data->piece.piece = tab;
}

void	ft_super_wod(t_data *data)
{
	int y;
	int x;
	int size_y;
	int size_x;
	int start;

	y = 0;
	size_y = data->piece.y;
	size_x = 1;
	start = 0;
	while (y < data->piece.y)
	{
		x = 0;
		while (data->piece.piece[y][x] && data->piece.piece[y][x] == '.')
			x++;
		if (data->piece.piece[y][x] == '\0')
			--size_y;
		if (start == 0)
		{
			data->piece.org_y = data->piece.y - size_y;
			++start;
		}
		y++;
	}
	y = 0;
	start = INT_MAX;
	while (y < data->piece.y)
	{
		x = 0;
		while (data->piece.piece[y][x])
		{
			if (data->piece.piece[y][x] == '*' && x < start)
				start = x;
			if (data->piece.piece[y][x] == '*' && x > size_x)
				size_x = x;
			x++;
		}
		y++;
	}
	data->piece.org_x = start;
	ft_finisher(data, size_y, size_x, start);
}

void	commando_para(t_data *data)
{
	ft_super_wod(data);
	if (CHECK_BIT(data->status, OPT_PLAYER1))
		supervision(data, 'O', 'o');
	else
		supervision(data, 'X', 'x');
	if (data->pos)
	{
		ft_putnbr(data->pos->x - data->piece.org_x);
		write(1, " ", 1);
		ft_putnbr(data->pos->y + data->piece.org_y);
		write(1, "\n", 1);
	}
	ft_free(data);
}
