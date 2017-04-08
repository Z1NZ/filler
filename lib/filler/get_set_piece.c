/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 07:18:30 by srabah            #+#    #+#             */
/*   Updated: 2016/10/26 07:18:32 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_set_piece(t_data *data, char *line)
{
	char	*tmp;
	char	**tab;

	if (ft_strstr(line, "Piece"))
	{
		data->status |= OPT_PLATEAU_SET;
		if ((tmp = ft_strchr(line, ':')))
			*tmp = ' ';
		tab = ft_strsplit(line, ' ');
		if (!check_digit(tab[1]))
			ft_error();
		if (!check_digit(tab[2]))
			ft_error();
		data->piece.x = ft_atoi(tab[2]);
		data->piece.y = ft_atoi(tab[1]);
		data->piece.piece = ft_memalloc(sizeof(char *) * data->piece.y);
		data->status |= OPT_PIECE_SET;
		tab_free(tab);
	}
}
