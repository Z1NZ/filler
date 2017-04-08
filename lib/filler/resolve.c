/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commando_para.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 07:00:44 by srabah            #+#    #+#             */
/*   Updated: 2016/11/11 14:02:29 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// int		claymore(t_data *data, int pos_x, int pos_y, char c, int save_x, int save_y)
// {
// 	char	**piece;
// 	char	**map;
// 	int		x;
// 	int		y;
// 	int		touch;

// 	touch = 0;
// 	y = 0;
// 	piece = data->piece.piece;
// 	map = data->map;


// 	while ((y + save_y) < data->piece.y &&
// 	 		pos_y + y < data->y)
// 	{
// 		x = 0;
// 		while (map[pos_y + y][pos_x + x] != '\0' 
// 			&& (x + save_x) <= data->piece.x 
// 			&& pos_x + x  < data->x)
// 		{
// 			if (touch > 1)
// 				return (0);
// 			if (piece[save_y + y][save_x + x] == '*' && map[pos_y + y][pos_x+ x] == c)
// 				touch++;
// 			else if (piece[save_y + y][save_x + x] == '*' && map[pos_y + y][pos_x+ x] != c && map[pos_y + y][pos_x+ x] != '.')
// 				return(0);
// 			++x;
// 		}
// 		++y;
// 	}
// 	if (touch == 1)
// 		return (1);
// 	return (0);
// }

// void	supervision(t_data *data, char c, int save_x, int save_y)
// {
// 	char	**tmp;
// 	int		x;
// 	int		y;

// 	y = 0;
// 	tmp = data->map;
// 	while (tmp[y] && y + (data->piece.y - save_y)  < data->y)
// 	{
// 		x = 0;
// 		while (tmp[y][x] &&  (data->piece.x - save_x) + x <= data->x)
// 		{
// 			if (claymore(data, x, y, c, save_x, save_y) == 1)
// 				add_pos(data, x - save_x, y - save_y);
// 			++x;
// 		}
// 		++y;
// 	}
// }

// void 	ft_color(char *map)
// {

// int i = 0;
// while(map[i] != '\0')
// {
//  		if (map[i] == 'O')
// 		{	
// 			ft_putstr_fd("\033[35m", 2);
// 			ft_putchar_fd('O', 2);
// 			ft_putstr_fd("\033[0m", 2);
// 		}
//  		else if (map[i] == 'X')
// 		{	
// 			ft_putstr_fd("\033[36m", 2);
// 			ft_putchar_fd('X', 2);
// 			ft_putstr_fd("\033[0m", 2);
// 		}
// 				else
// 		{	
// 			ft_putstr_fd("\033[37m", 2);
//   			ft_putchar_fd('.', 2);
//   			ft_putstr_fd("\033[0m", 2);
//   		}
//   		i++;
// }
// ft_putstr_fd("\n", 2);
// }

// void	ft_super_wod(t_data *data)
// {
// 	int y;
// 	int save_y;
// 	int x;
// 	int save_x;

// 	save_x = INT_MAX;
// 	y = 0;
// 	while(ft_strstr(data->piece.piece[y],"*") == NULL)
// 		y++;
// 	save_y = y;
// 	while(y < data->piece.y)
// 	{
// 		x = 0;
// 		while(x < data->piece.x)
// 		{
// 			if (data->piece.piece[y][x] == '*' && x < save_x)
// 				save_x = x;
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (save_x == 0)
// 		ft_putstr_fd("0\n", 2);
// 	if (save_y == 0)
// 		ft_putstr_fd("0\n", 2);
// 	// debug(data);
// 	if (CHECK_BIT(data->status, OPT_PLAYER1))
// 		supervision(data, 'O', save_x, save_y);
// 	else
// 		supervision(data, 'X', save_x, save_y);
// }










int		check_add(t_data *data, int pos_x, int pos_y, char c, int cut_x, int cut_y)
{
	char	**piece;
	char	**map;
	int		x;
	int		y;
	int		touch;

	touch = 0;
	y = 0;
	piece = data->piece.piece;
	map = data->map.map;


	while (pos_y + y < data->map.y && cut_y + y < data->piece.y)
	{
		x = 0;
		while (pos_x + x  < data->map.x && cut_x + x < data->piece.x)
		{
			if (touch > 1)
				return (0);
			if (piece[cut_y + y][cut_x + x] == '*' && map[pos_y + y][pos_x + x] == c)
				touch++;
			else if (piece[cut_y + y][cut_x + x] == '*' && map[pos_y + y][pos_x+ x] != c && map[pos_y + y][pos_x+ x] != '.')
				return(0);
			++x;
		}
		++y;
	}
	if (touch == 1)
		return (1);
	return (0);
}




void	check_map(t_data *data, char c, int cut_x, int cut_y)
{
	char	**tmp;
	int		x;
	int		y;

	y = 0;
	tmp = data->map.map;
	while (tmp[y])
	{
		x = 0;
		while (tmp[y][x]!= '\0')
		{
			if (check_add(data, x, y, c, cut_x, cut_y) == 1)
				add_pos(data, x - cut_x, y - cut_y);
			++x;
		}
		++y;
	}
}


void	cut_piece(t_data *data)
{
	int y;
	int x;
	int cut_y;
	int cut_x;

	y = 0;
	while(ft_strstr(data->piece.piece[y],"*") == NULL)
		y++;
	cut_y = y;
	cut_x = INT_MAX;
	while(y < data->piece.y)
	{
		x = 0;
		while(x < data->piece.x)
		{
			if (data->piece.piece[y][x] == '*' && x < cut_x)
				cut_x = x;
			x++;
		}
		y++;
	}
	if (cut_x == INT_MAX)
		cut_x = 0;
	if (CHECK_BIT(data->status, OPT_PLAYER1))
		check_map(data, 'O', cut_x, cut_y);
	else
		check_map(data, 'X', cut_x, cut_y);
}

void	resolve(t_data *data)
{
	cut_piece(data);
	// ft_super_wod(data);

	if (data->pos->next)
	{
		ft_putnbr((data->pos->next->y));
		write(1, " ", 1);
		ft_putnbr((data->pos->next->x));
		write(1, "\n", 1);
	}
	else
		write(1, "0 0\n", 4);
	ft_free(data);
}
