#include "filler.h"

void	ft_del_list(t_pos *pos)
{
	t_pos *tmp;

	while(pos != NULL)
	{
		tmp = pos;
		pos = pos->next;
		free(tmp);
	}
}