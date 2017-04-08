#include "filler.h"

void	ft_free(t_data *data)
{
	free((data->map));
	free((data->pos));
	data->pos = NULL;
	data->map = NULL;
	data->x = 0;
	data->y = 0;
	data->piece.x = 0;
	data->piece.org_x = 0;
	data->piece.y = 0;
	data->piece.org_y = 0;
	data->piece.curent = 0;
	data->curent = 0;

	data->status ^= OPT_PLATEAU_SET;
	data->status ^= OPT_MAP_SET;
	data->status ^= OPT_PIECE_SET;
	data->status ^= OPT_PIECE_FULL;

}