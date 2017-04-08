
#include "filler.h"


t_pos		*get_midel_top(t_data *data)
{
	t_pos	*tmp;
	t_pos	*ret;
	int		value;
	int		old;
	int		top;

	tmp = data->pos;
	value = data->map.x / 2;
	top  = data->map.y / 2;
	old = INT_MAX;
	while(tmp)
	{
		if (ABS(value - tmp->x) < old && tmp->y < top)
		{
			ret = tmp;
		}
		tmp = tmp->next;
	}
	if (ret == NULL )
	return(ret);
}

t_pos		*top_list(t_data *data, int pos)
{
	// if (pos == LEFT)
	if (pos == MIDLE)
		return(get_midel_top(data));
	else
		return(data->pos);
}