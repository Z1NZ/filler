/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 11:14:38 by srabah            #+#    #+#             */
/*   Updated: 2017/04/11 11:14:39 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pos		*get_left_left(t_data *data)
{
	t_pos	*tmp;
	t_pos	*ret;
	int		old_x;

	tmp = data->pos;
	old_x = INT_MAX;
	ret = NULL;
	while (tmp)
	{
		if (tmp->x < old_x)
		{
			old_x = tmp->x;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

t_pos		*left_list(t_data *data, int pos)
{
	if (pos == MIDLE)
		return (get_left_left(data));
	else if (pos == UP)
		return (top_list(data, LEFT));
	else if (pos == DOWN)
		return (bot_list(data, LEFT));
	else
		return (data->pos);
}
