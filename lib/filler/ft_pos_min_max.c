/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 09:50:15 by srabah            #+#    #+#             */
/*   Updated: 2017/04/11 09:50:16 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		min_pos_x(t_data *data, char c)
{
	int y;
	int x;
	int ret_x;

	y = 0;
	ret_x = INT_MAX;
	while (MAP.map[y])
	{
		x = 0;
		while (MAP.map[y][x])
		{
			if (MAP.map[y][x] == c && x < ret_x)
				ret_x = x;
			x++;
		}
		y++;
	}
	return (ret_x);
}

int		max_pos_x(t_data *data, char c)
{
	int y;
	int x;
	int ret_x;

	y = 0;
	ret_x = 0;
	while (MAP.map[y])
	{
		x = 0;
		while (MAP.map[y][x])
		{
			if (MAP.map[y][x] == c && x > ret_x)
				ret_x = x;
			x++;
		}
		y++;
	}
	return (ret_x);
}

int		min_pos_y(t_data *data, char c)
{
	int y;
	int x;

	y = 0;
	while (MAP.map[y])
	{
		x = 0;
		while (MAP.map[y][x])
		{
			if (MAP.map[y][x] == c)
				return (y);
			x++;
		}
		y++;
	}
	return (0);
}

int		max_pos_y(t_data *data, char c)
{
	int y;
	int x;
	int ret_y;

	y = 0;
	ret_y = 0;
	while (MAP.map[y])
	{
		x = 0;
		while (MAP.map[y][x])
		{
			if (MAP.map[y][x] == c && y > ret_y)
				ret_y = y;
			x++;
		}
		y++;
	}
	return (ret_y);
}
