/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:09:23 by srabah            #+#    #+#             */
/*   Updated: 2017/04/11 11:09:25 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_pos		*get_right_top(t_data *data)
{
	t_pos	*tmp;
	t_pos	*ret;
	int		old_x;
	int		old_y;

	tmp = data->pos;
	old_x = 0;
	old_y = INT_MAX;
	ret = NULL;
	while (tmp)
	{
		if (tmp->x >= old_x && tmp->y <= old_y)
		{
			old_x = tmp->x;
			old_y = tmp->y;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

static t_pos		*get_midel_top(t_data *data)
{
	t_pos	*tmp;
	t_pos	*ret;
	int		value;
	int		old_x;
	int		old_y;

	tmp = data->pos;
	value = data->map.x / 2;
	old_x = INT_MAX;
	old_y = INT_MAX;
	ret = NULL;
	while (tmp)
	{
		if (ABS(value - tmp->x) <= old_x && tmp->y <= old_y)
		{
			old_x = tmp->x;
			old_y = tmp->y;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_pos				*top_list(t_data *data, int pos)
{
	if (pos == RIGHT)
		return (get_right_top(data));
	else if (pos == MIDLE)
		return (get_midel_top(data));
	else
		return (data->pos);
}
