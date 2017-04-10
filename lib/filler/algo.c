#include "filler.h"


int size_x_real_piece(t_data *data)
{
	int x;
	int y;
	int size_x;
	char **tab;

	tab = data->piece.piece;
	y = 0;
	size_x = 0;
	while(tab[y])
	{
		x = 0;
		while(tab[y][x])
		{
			if (tab[y][x] ==  '*' &&  x > size_x)
				size_x = x;
			x++;
		}
		y++;
	}
	return(size_x);
}


int size_y_real_piece(t_data *data)
{
	char **tab;
	int y;
	int size_y;

	tab = data->piece.piece;
	y = 0;
	size_y = 0;
	while(tab[y])
	{
		if (ft_strstr(tab[y], "*"))
			size_y++;
		y++;
	}
	return(size_y);
}


t_pos		*close_position(t_data *data, char c, char b)
{
	t_pos	*tmp;
	int		y;
	int		x;

	y = 0;
	while(data->map.map[y])
	{
		x = 0;
		while(data->map.map[y][x])
		{
			if (data->map.map[y][x] == c || data->map.map[y][x] == b )
				break;
			x++;
		}
		if (x != data->map.x)
			break;
		y++;
	}
	tmp = data->pos;
	int old_x = INT_MAX;
	int old_y = INT_MAX;
	t_pos *ret;

	ret = NULL;
	while(tmp)
	{
		if (ABS(tmp->x - x) < old_x && ABS(tmp->y - y) < old_y)
		{
			// fprintf(stderr,	"tmp[%d][%d]", tmp->y, tmp->x);
			old_y = ABS(tmp->y  - y);
			old_x = ABS(tmp->x - x);
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return(ret); 
}





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


t_pos	*algo_second(t_data *data)
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
		return(close_position(data, 'o', 'O'));
}

t_pos	*algo_first(t_data *data)
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

		// fprintf(stderr, "max x = > %d map x [%d]\n", max_x, data->map.x);
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

t_pos		*algo(t_data *data)
{
	if (data->map.x < 20)
	{
		if (CHECK_BIT(data->status, OPT_PLAYER1))
			return(algo_first(data));
		else
			return(algo_second(data));
	}
	else if (CHECK_BIT(data->status, OPT_PLAYER1))
		return(close_position(data, 'X', 'x'));
	else
		return(close_position(data, 'O', 'o'));

}
