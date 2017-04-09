#include "filler.h"

int min_pos_x(t_data *data)
{
	int y;
	int x;
	int ret_x;
	y = 0;
	ret_x = INT_MAX;

	while(data->map.map[y])
	{
		x = 0;
		while(data->map.map[x])
		{
			if (data->map.map[y][x] == 'X' && x < ret_x)
				ret_x = x;
			x++;
		}
		y++;
	}
	return(ret_x);
}

int max_pos_x(t_data *data)
{
	int y;
	int x;
	int ret_x;
	y = 0;
	ret_x = 0;

	while(data->map.map[y])
	{
		x = 0;
		while(data->map.map[x])
		{
			if (data->map.map[y][x] == 'O' && x > ret_x)
				ret_x = x;
			x++;
		}
		y++;
	}
	return(ret_x);
}

int min_pos_y(t_data *data)
{
	int y;
	int x;

	y = 0;
	while(data->map.map[y])
	{
		x = 0;
		while(data->map.map[x])
		{
			if (data->map.map[y][x] == 'O')
				return(y);
			x++;
		}
		y++;
	}
	return(0);
}

int max_pos_y(t_data *data)
{
	int y;
	int x;
	int ret_y;
	y = 0;
	ret_y = 0;

	while(data->map.map[y])
	{
		x = 0;
		while(data->map.map[x])
		{
			if (data->map.map[y][x] == 'O' && y > ret_y)
				ret_y = y;
			x++;
		}
		y++;
	}
	return(ret_y);
}


t_pos	*algo_second(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data);
	min_x = min_pos_x(data);
	min_y = min_pos_y(data);
	max_y = max_pos_y(data);

	if (min_x == 0 || min_y == 0)
		return(right_list(data, RIGHT));
	else if (min_x > 0)
		return(top_list(data, LEFT));
	else if (max_x < data->map.x)
		return(right_list(data, RIGHT));
	else
		return(bot_list(data, LEFT));
}

t_pos	*algo_first(t_data *data)
{
	int max_x;
	int min_x;
	int min_y;
	int max_y;

	max_x = max_pos_x(data);
	min_x = min_pos_x(data);
	min_y = min_pos_y(data);
	max_y = max_pos_y(data);

	if (max_x == data->map.x || max_y == data->map.y)
		return(top_list(data, LEFT));
	else if (max_x < data->map.x)
		return(bot_list(data, RIGHT));
	else
		return(bot_list(data, LEFT));
}

t_pos		*algo(t_data *data)
{
	if (CHECK_BIT(data->status, OPT_PLAYER1))
		return(algo_first(data));
	else
		return(algo_second(data));
}