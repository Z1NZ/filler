#include "filler.h"

void	ft_free(t_data *data)
{


	ft_putstr_fd("pos \n", 2);
	ft_del_list(data->pos);

	ft_putstr_fd("map. \n", 2);
	tab_free(data->map.map);
	ft_putstr_fd("piece. \n", 2);
	tab_free(data->piece.piece);
	data->pos = NULL;
	data->piece.piece = NULL;
	data->map.map= NULL;
	data->map.x = 0;
	data->map.y = 0;
	data->map.curent = 0;
	



	data->piece.x = 0;
	data->piece.y = 0;
	data->piece.curent = 0;

	data->status ^= OPT_PLATEAU_SET;
	data->status ^= OPT_MAP_SET;
	data->status ^= OPT_PIECE_SET;
	data->status ^= OPT_PIECE_FULL;

}