/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 08:13:05 by srabah            #+#    #+#             */
/*   Updated: 2016/10/26 08:13:07 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(int argc, char **argv)
{
	t_data	*data;
	char	*line;

	(void)argc;
	data = ft_memalloc(sizeof(t_data));
	data->map = NULL;
	while(0xDEADBEEF)
	{
		if (get_next_line(STDIN_FILENO, &line))
		{
			 fprintf(stderr, "[[%s]]\n", line);
			if (!CHECK_BIT(data->status, OPT_PLAYER_SET))
				get_player(data, line, *argv);
			else if (!CHECK_BIT(data->status, OPT_PLATEAU_SET))
				get_set_map(data, line);
			else if (CHECK_BIT(data->status, OPT_PLATEAU_SET)
					&& !CHECK_BIT(data->status, OPT_MAP_SET))
				get_map(data, line);
			else if (!CHECK_BIT(data->status, OPT_PIECE_SET))
				get_set_piece(data, line);
			else if (CHECK_BIT(data->status, OPT_PIECE_SET)
					&& !CHECK_BIT(data->status, OPT_PIECE_FULL))
			{
				get_piece(data, line);
			}
			if (CHECK_BIT(data->status, OPT_PIECE_FULL))
				commando_para(data);
			free(line);
		}
	}
	return (0);
}
