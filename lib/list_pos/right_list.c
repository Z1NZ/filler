#include "filler.h"

static t_pos	*get_right_right(t_data *data)
{
	t_pos	*tmp;
	t_pos	*ret;
	int		value;
	int		value_x;
	int		old_x;
	int		old_y;

	tmp = data->pos;
	value = data->map.y / 2;
	value_x = data->map.x / 2;
	old_x = 0;
	old_y = INT_MAX;
	ret = NULL;
	while(tmp)
	{
		if (ABS(value_x - tmp->x) >= old_x)
		{
			old_x = tmp->x;
			old_y = tmp->y;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return(ret);
}



t_pos		*right_list(t_data *data, int pos)
{
	if (pos == MIDLE)
		return (get_right_right(data));
	else if (pos == UP)
		return (top_list(data, RIGHT));
	else if (pos == DOWN)
		return (bot_list(data, RIGHT));
	else
		return(data->pos);
}