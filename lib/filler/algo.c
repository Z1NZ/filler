/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 09:39:46 by srabah            #+#    #+#             */
/*   Updated: 2017/04/11 09:39:47 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pos		*map00_p2(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data, 'X');
	min_x = min_pos_x(data, 'X');
	min_y = min_pos_y(data, 'X');
	max_y = max_pos_y(data, 'X');
	if (min_y != 0 && !ft_strstr(data->map.map[0], "O"))
		return (top_list(data, RIGHT));
	else if (max_y < data->map.y)
		return (bot_list(data, LEFT));
	else
		return (data->pos);
}

t_pos		*map00_p1(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data, 'O');
	min_x = min_pos_x(data, 'O');
	min_y = min_pos_y(data, 'O');
	max_y = max_pos_y(data, 'O');
	if (max_x < data->map.x - 1 && min_y > 0)
		return (top_list(data, RIGHT));
	else if (max_y < data->map.y - 1)
		return (bot_list(data, LEFT));
	else
		return (right_list(data, MIDLE));
}

t_pos		*map01_p1(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data, 'O');
	min_x = min_pos_x(data, 'O');
	min_y = min_pos_y(data, 'O');
	max_y = max_pos_y(data, 'O');
	if (max_x < data->map.x - 1)
		return (bot_list(data, RIGHT));
	else if (min_y != 0 && min_x != 0)
		return (top_list(data, LEFT));
	else
		return (right_list(data, MIDLE));
}

t_pos		*map01_p2(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data, 'X');
	min_x = min_pos_x(data, 'X');
	min_y = min_pos_y(data, 'X');
	max_y = max_pos_y(data, 'X');
	if (min_y > (data->map.y / 2) - 2)
		return (top_list(data, LEFT));
	else if (min_x > 0)
		return (bot_list(data, LEFT));
	else
		return (top_list(data, RIGHT));
}

t_pos		*algo(t_data *data)
{
	if (data->map.x < 20)
	{
		if (CHECK_BIT(data->status, OPT_PLAYER1))
			return (map00_p1(data));
		else
			return (map00_p2(data));
	}
	else if (data->map.x < 60)
	{
		if (CHECK_BIT(data->status, OPT_PLAYER1))
			return (map01_p1(data));
		else
			return (map01_p2(data));
	}
	else
	{
		if (CHECK_BIT(data->status, OPT_PLAYER1))
			return (map02_p1(data));
		else
			return (map02_p2(data));
	}
}
