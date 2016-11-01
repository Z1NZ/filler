/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 07:13:01 by srabah            #+#    #+#             */
/*   Updated: 2016/10/26 07:13:03 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(t_data *data, char *line, char *exe)
{
	if (ft_strstr(line, exe))
	{
		data->status |= OPT_PLAYER_SET;
		if (ft_strstr(line, "p1"))
			data->status |= OPT_PLAYER1;
		else if (ft_strstr(line, "p2"))
			data->status |= OPT_PLAYER2;
	}
}
