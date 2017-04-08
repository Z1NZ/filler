/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 07:08:54 by srabah            #+#    #+#             */
/*   Updated: 2016/10/26 07:08:57 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_tab(char **tab)
{
	if (tab)
	{
		while (*tab)
		{
			// fprintf(stderr, "%s\n", *tab);
			tab++;
		}
	}
}

void	debug(t_data *data)
{
	(void)data;
	// fprintf(stderr, "===========================================================================\n");
	// fprintf(stderr, "status	= [%d]\n", data->status);
	// if (CHECK_BIT(data->status, OPT_PLAYER1))
	// 	fprintf(stderr, "player 1\n");
	// else
	// 	fprintf(stderr, "player 2\n");
	// fprintf(stderr, "map y	= [%d]\n", data->y);
	// fprintf(stderr, "map x	= [%d]\n", data->x);
	// fprintf(stderr, "curent	= [%d]\n", data->curent);
	// fprintf(stderr, "map x[%d] y[%d]:\n", data->x, data->y);
	// ft_print_tab(data->map);
	// fprintf(stderr, "piece y	= [%d]\n", data->piece.y);
	// fprintf(stderr, "piece x	= [%d]\n", data->piece.x);
	// fprintf(stderr, "piece curent = [%d]\n", data->piece.curent);
	// fprintf(stderr, "piece y[%d] x[%d]:\n", data->piece.y, data->piece.x);
	// ft_print_tab(data->piece.piece);
	// fprintf(stderr, "===========================================================================\n");
	
}
