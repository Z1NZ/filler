#include "filler.h"

static t_pos	*get_left_left(t_data *data)
{
	t_pos	*tmp;
	t_pos	*ret;
	int		value;
	int		old_x;
	int		old_y;

	tmp = data->pos;
	value = data->map.y / 2;
	old_x = INT_MAX;
	old_y = INT_MAX;
	ret = NULL;
	while(tmp)
	{
		if (ABS(value - tmp->y) <= old_y && tmp->x <= old_x)
		{
			old_x = tmp->x;
			old_y = tmp->y;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return(ret);
}



t_pos		*left_list(t_data *data, int pos)
{
	if (pos == MIDLE)
		return (get_left_left(data));
	else if (pos == UP)
		return (top_list(data, LEFT));
	else if (pos == DOWN)
		return (bot_list(data, LEFT));
	else
		return(data->pos);
}