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

int		check_add(t_data *data, int *p, char c, int *b)
{
	int		x;
	int		y;
	int		touch;

	touch = 0;
	y = 0;
	while (p[0] + y < MAP.y && b[0] + y < PIECE.y)
	{
		x = 0;
		while (p[1] + x <= MAP.x && b[1] + x < PIECE.x)
		{
			if (touch > 1)
				return (0);
			if (P_P[b[0] + y][b[1] + x] == '*' && M_M[p[0] + y][p[1] + x] == c)
				touch++;
			else if (P_P[b[0] + y][b[1] + x] == '*'
		&& M_M[p[0] + y][p[1] + x] != c && M_M[p[0] + y][p[1] + x] != '.')
				return (0);
			++x;
		}
		++y;
	}
	if (touch == 1 && (b[0] + y) == PIECE.y)
		return (1);
	return (0);
}

void	check_map(t_data *data, char c, int *tab)
{
	char	**tmp;
	int		cor[2];

	cor[0] = 0;
	tmp = M_M;
	while (tmp[cor[0]])
	{
		cor[1] = 0;
		while (tmp[cor[0]][cor[1]] != '\0')
		{
			if (check_add(data, cor, c, tab) == 1)
				add_pos(data, cor[1] - tab[1], cor[0] - tab[0]);
			++cor[1];
		}
		++cor[0];
	}
}

void	cut_piece(t_data *data)
{
	int y;
	int x;
	int cut[2];

	y = 0;
	while (ft_strstr(P_P[y], "*") == NULL)
		y++;
	cut[0] = y;
	cut[1] = INT_MAX;
	while (y < PIECE.y)
	{
		x = 0;
		while (x < PIECE.x)
		{
			if (P_P[y][x] == '*' && x < cut[1])
				cut[1] = x;
			x++;
		}
		y++;
	}
	if (cut[1] == INT_MAX)
		cut[1] = 0;
	(CHECK_BIT(data->status, OPT_PLAYER1)) ? check_map(data, 'O', cut)
	: check_map(data, 'X', cut);
}

void	resolve(t_data *data)
{
	t_pos *tmp;

	cut_piece(data);
	if ((tmp = algo(data)))
	{
		ft_putnbr((tmp->y));
		write(1, " ", 1);
		ft_putnbr((tmp->x));
		write(1, "\n", 1);
	}
	else
		write(1, "0 0\n", 4);
	ft_free(data);
}
