/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 09:21:00 by srabah            #+#    #+#             */
/*   Updated: 2017/04/11 09:21:21 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	add_pos(t_data *data, int x, int y)
{
	t_pos	*ptr;
	t_pos	*tmp;

	ptr = ft_memalloc(sizeof(t_pos));
	ptr->x = x;
	ptr->y = y;
	ptr->next = NULL;
	if (data->pos == NULL)
		data->pos = ptr;
	else
	{
		tmp = data->pos;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ptr;
	}
}
