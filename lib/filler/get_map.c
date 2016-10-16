#include "filler.h"

void	get_map(t_data *data, char *line)
{
	char	**tmp;

	tmp = ft_strsplit(line , ' ');
	if (ft_tablen(tmp) > 1)
	{
		data->curent = ft_atoi(tmp[0]);
		if (data->curent <= data->y)
		{
			if (data->map[data->curent])
				ft_memdel((void**)&(data->map[data->curent]));
			data->map[data->curent] = ft_strdup(tmp[1]);
		}
		if (data->curent == (data->y - 1))
			data->status |= OPT_MAP_SET;
	}
}