#include "filler.h"

void	add_pos(t_data *data, int x, int y)
{
	t_pos	*ptr;
	t_pos	*tmp;

	ptr = ft_memalloc(sizeof(t_pos));
	ptr->x = x;
	ptr->y = y;
	ptr->next = NULL;
	if (data->pos == NULL)
		data->pos = ptr;
	else
	{
		tmp = data->pos;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = ptr;
	}
}