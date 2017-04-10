#include "filler.h"


// int size_x_real_piece(t_data *data)
// {
// 	int x;
// 	int y;
// 	int size_x;
// 	char **tab;

// 	tab = data->piece.piece;
// 	y = 0;
// 	size_x = 0;
// 	while(tab[y])
// 	{
// 		x = 0;
// 		while(tab[y][x])
// 		{
// 			if (tab[y][x] ==  '*' &&  x > size_x)
// 				size_x = x;
// 			x++;
// 		}
// 		y++;
// 	}
// 	return(size_x);
// }


// int size_y_real_piece(t_data *data)
// {
// 	char **tab;
// 	int y;
// 	int size_y;

// 	tab = data->piece.piece;
// 	y = 0;
// 	size_y = 0;
// 	while(tab[y])
// 	{
// 		if (ft_strstr(tab[y], "*"))
// 			size_y++;
// 		y++;
// 	}
// 	return(size_y);
// }







int min_pos_x(t_data *data, char c)
{
	int y;
	int x;
	int ret_x;
	y = 0;
	ret_x = INT_MAX;

	while(data->map.map[y])
	{
		x = 0;
		while(data->map.map[y][x])
		{
			if (data->map.map[y][x] == c && x < ret_x)
				ret_x = x;
			x++;
		}
		y++;
	}
	return(ret_x);
}

int max_pos_x(t_data *data, char c)
{
	int y;
	int x;
	int ret_x;
	y = 0;
	ret_x = 0;

	while(data->map.map[y])
	{
		x = 0;
		while(data->map.map[y][x])
		{
			if (data->map.map[y][x] == c && x > ret_x)
				ret_x = x;
			x++;
		}
		y++;
	}
	return(ret_x);
}

int min_pos_y(t_data *data, char c)
{
	int y;
	int x;

	y = 0;
	while(data->map.map[y])
	{
		x = 0;
		while(data->map.map[y][x])
		{
			if (data->map.map[y][x] == c)
				return(y);
			x++;
		}
		y++;
	}
	return(0);
}

int max_pos_y(t_data *data, char c)
{
	int y;
	int x;
	int ret_y;
	y = 0;
	ret_y = 0;

	while(data->map.map[y])
	{
		x = 0;
		while(data->map.map[y][x])
		{
			if (data->map.map[y][x] == c && y > ret_y)
				ret_y = y;
			x++;
		}
		y++;
	}
	return(ret_y);
}


t_pos	*map00_p2(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data, 'X');
	min_x = min_pos_x(data, 'X');
	min_y = min_pos_y(data, 'X');
	max_y = max_pos_y(data, 'X');

	if (min_y != 0 && !ft_strstr(data->map.map[0], "O"))
		return(top_list(data, RIGHT));
	else if (max_y < data->map.y)
		return(bot_list(data, LEFT));
	else
		return(data->pos);
}

t_pos	*map00_p1(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data, 'O');
	min_x = min_pos_x(data, 'O');
	min_y = min_pos_y(data, 'O');
	max_y = max_pos_y(data, 'O');
	// usleep(50000);
	if (max_x < data->map.x - 1  && min_y > 0)
	{
		return(top_list(data, RIGHT));
	}
	else if (max_y < data->map.y - 1)
	{
		return(bot_list(data, LEFT));
	}
	else
	{
		return(right_list(data, MIDLE));
	}
}

t_pos		*map01_p1(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data, 'O');
	min_x = min_pos_x(data, 'O');
	min_y = min_pos_y(data, 'O');
	max_y = max_pos_y(data, 'O');
	// usleep(50000);
	if (max_x < data->map.x - 1)
	{
		return(bot_list(data, RIGHT));
	}
	else if (min_y != 0 && min_x != 0)
	{
		return(top_list(data, LEFT));
	}
	else
	{
		return(right_list(data, MIDLE));
	}
}


t_pos		*map01_p2(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data, 'X');
	min_x = min_pos_x(data, 'X');
	min_y = min_pos_y(data, 'X');
	max_y = max_pos_y(data, 'X');
	// usleep(50000);
	if (min_y > (data->map.y / 2) - 2)
		return(top_list(data, LEFT));
	else if (min_x > 0)
	{

		return(bot_list(data, LEFT));
	}
	else
	{
		return(top_list(data, RIGHT));
	}
}















t_pos		*map02_p1(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data, 'O');
	min_x = min_pos_x(data, 'O');
	min_y = min_pos_y(data, 'O');
	max_y = max_pos_y(data, 'O');
	// usleep(50000);
	if (min_y > (data->map.y / 2) + 6)
	{
		return(top_list(data, LEFT));
	}
	else if (min_x > 0)
	{
		if (min_x - 50 > 0)
			return(left_list(data, DOWN));
		else
			return(left_list(data, MIDLE));
	}
	else
	{
		if (min_y != 0)
		return(top_list(data, RIGHT));
		else if (max_y != data->map.y - 1)
			return(bot_list(data, RIGHT));
		else
			return(bot_list(data, MIDLE));

	}
	// else if (min_y != 0 )
	// {
	// 	return(top_list(data, RIGHT));
	// }
	// else
	// {
	// 	return(top_list(data, LEFT));
	// }
}


t_pos		*map02_p2(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data, 'X');
	min_x = min_pos_x(data, 'X');
	min_y = min_pos_y(data, 'X');
	max_y = max_pos_y(data, 'X');

	if (max_x < data->map.x - 1)
	{
		return (bot_list(data, RIGHT));
	}
	else if (min_x != 0)
		return (left_list(data, MIDLE));
	else if (!ft_strstr(data->map.map[0], "O"))
		return (bot_list(data, MIDLE));
	else
		return(top_list(data, LEFT));
}





















t_pos		*algo(t_data *data)
{
	if (data->map.x < 20)
	{
		if (CHECK_BIT(data->status, OPT_PLAYER1))
			return(map00_p1(data));
		else
			return(map00_p2(data));
	}
	else if (data->map.x < 60)
	{

		if (CHECK_BIT(data->status, OPT_PLAYER1))
			return(map01_p1(data));
		else
			return(map01_p2(data));
	}
	else
	{
		if (CHECK_BIT(data->status, OPT_PLAYER1))
			return(map02_p1(data));
		else
			return(map02_p2(data));
	}
}
