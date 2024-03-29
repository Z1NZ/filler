/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:11:05 by srabah            #+#    #+#             */
/*   Updated: 2017/04/11 11:11:06 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_pos		*get_right_bot(t_data *data)
{
	t_pos	*tmp;
	t_pos	*ret;
	int		old_x;
	int		old_y;

	tmp = data->pos;
	old_x = 0;
	old_y = 0;
	ret = NULL;
	while (tmp)
	{
		if (tmp->x >= old_x && tmp->y >= old_y)
		{
			old_x = tmp->x;
			old_y = tmp->y;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

static t_pos		*get_midel_bot(t_data *data)
{
	t_pos	*tmp;
	t_pos	*ret;
	int		value;
	int		old_x;
	int		old_y;

	tmp = data->pos;
	value = data->map.x / 2;
	old_x = INT_MAX;
	old_y = 0;
	ret = NULL;
	while (tmp)
	{
		if (ABS(value - tmp->x) <= old_x && tmp->y >= old_y)
		{
			old_x = tmp->x;
			old_y = tmp->y;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

static t_pos		*get_left_bot(t_data *data)
{
	t_pos	*tmp;
	t_pos	*ret;
	int		old_x;
	int		old_y;

	tmp = data->pos;
	old_x = INT_MAX;
	old_y = 0;
	ret = NULL;
	while (tmp)
	{
		if (tmp->x <= old_x && tmp->y >= old_y)
		{
			old_x = tmp->x;
			old_y = tmp->y;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_pos				*bot_list(t_data *data, int pos)
{
	if (pos == RIGHT)
		return (get_right_bot(data));
	else if (pos == MIDLE)
		return (get_midel_bot(data));
	else if (pos == LEFT)
		return (get_left_bot(data));
	else
		return (data->pos);
}
