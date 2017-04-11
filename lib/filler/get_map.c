/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 07:10:20 by srabah            #+#    #+#             */
/*   Updated: 2016/10/26 07:10:24 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_map(t_data *data, char *line)
{
	char	**tmp;
	int		cur;

	tmp = ft_strsplit(line, ' ');
	if (ft_tablen(tmp) > 1)
	{
		cur = (int)ft_atoi(tmp[0]);
		if (cur <= data->map.y)
			data->map.map[cur] = ft_strdup(tmp[1]);
		if (cur == (data->map.y - 1))
		{
			data->status |= OPT_MAP_SET;
			data->map.map[cur + 1] = NULL;
			if (COLOR == 1)
			{
				ft_putstr_fd("\n", 2);
				ft_color(data->map.map);
			}
		}
	}
	if (tmp)
		tab_free(tmp);
}
