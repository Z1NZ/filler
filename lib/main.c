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

void	loop(t_data *data, char *argv)
{
	char	*line;

	while ((get_next_line(STDIN_FILENO, &line)) >= 0)
	{
		if (!CHECK_BIT(data->status, OPT_PLAYER_SET))
			get_player(data, line, argv);
		else if (!CHECK_BIT(data->status, OPT_PLATEAU_SET))
			get_set_map(data, line);
		else if (CHECK_BIT(data->status, OPT_PLATEAU_SET)
			&& !CHECK_BIT(data->status, OPT_MAP_SET))
			get_map(data, line);
		else if (!CHECK_BIT(data->status, OPT_PIECE_SET))
			get_set_piece(data, line);
		else if (CHECK_BIT(data->status, OPT_PIECE_SET)
			&& !CHECK_BIT(data->status, OPT_PIECE_FULL))
			get_piece(data, line);
		if (CHECK_BIT(data->status, OPT_PIECE_FULL))
			resolve(data);
		free(line);
	}
}

int		main(int argc, char **argv)
{
	t_data	*data;

	(void)argc;
	data = ft_memalloc(sizeof(t_data));
	data->pos = NULL;
	data->map.map = NULL;
	if (COLOR)
		ft_putstr_fd("\x1b[2J\e[?25l", 2);
	loop(data, *argv);
	ft_putstr_fd("\e[?25h", 2);
	free(data);
	sleep(200);
	return (0);
}
