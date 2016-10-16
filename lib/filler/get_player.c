#include "filler.h"

void get_player(t_data *data, char *line, char *exe)
{
	printf("%s\n", exe);
	if (ft_strstr(line, exe))
	{
		data->status |= OPT_PLAYER_SET;
		if (ft_strstr(line , "p1"))
			data->status |= OPT_PLAYER1;
		else if (ft_strstr(line , "p2"))
			data->status |= OPT_PLAYER2;
	}
}