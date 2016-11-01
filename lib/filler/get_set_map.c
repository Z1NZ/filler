/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 07:18:04 by srabah            #+#    #+#             */
/*   Updated: 2016/10/26 07:18:06 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_set_map(t_data *data, char *line)
{
	char *tmp;
	char **tab;

	if (ft_strstr(line, "Plateau"))
	{
		if ((tmp = ft_strchr(line, ':')))
			*tmp = '\0';
		tab = ft_strsplit(line, ' ');
		if (!check_digit(tab[1]))
			ft_error();
		if (!check_digit(tab[2]))
			ft_error();
		data->x = ft_atoi(tab[2]);
		data->y = ft_atoi(tab[1]);
		data->map = ft_memalloc(sizeof(char *) * data->y + 1);
		*tmp = ':';
		data->status |= OPT_PLATEAU_SET;
	}
}
