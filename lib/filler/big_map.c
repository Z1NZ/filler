/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 09:42:34 by srabah            #+#    #+#             */
/*   Updated: 2017/04/11 09:42:56 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pos		*map02_p1(t_data *data)
{
	int min_x;
	int min_y;
	int max_y;

	min_x = min_pos_x(data, 'O');
	min_y = min_pos_y(data, 'O');
	max_y = max_pos_y(data, 'O');
	if (min_y > (data->map.y / 2) + 6)
		return (top_list(data, LEFT));
	else if (min_x > 0)
	{
		if (min_x - 50 > 0)
			return (left_list(data, DOWN));
		else
			return (left_list(data, MIDLE));
	}
	else
	{
		if (min_y != 0)
			return (top_list(data, RIGHT));
		else if (max_y != data->map.y - 1)
			return (bot_list(data, RIGHT));
		else
			return (bot_list(data, MIDLE));
	}
}

t_pos		*map02_p2(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data, 'X');
	min_x = min_pos_x(data, 'X');
	min_y = min_pos_y(data, 'X');
	max_y = max_pos_y(data, 'X');
	if (max_x < data->map.x - 1)
		return (bot_list(data, RIGHT));
	else if (min_x != 0)
		return (left_list(data, MIDLE));
	else if (!ft_strstr(data->map.map[0], "O"))
		return (bot_list(data, MIDLE));
	else
		return (top_list(data, LEFT));
}
