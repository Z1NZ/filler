#include "filler.h"

void	get_piece(t_data *data, char *line)
{
	if (check_piece(line) && data->piece.curent <= data->piece.y)
	{
		if (data->piece.piece[data->piece.curent])
			ft_memdel((void**)&(data->piece.piece[data->piece.curent]));
		data->piece.piece[data->piece.curent] = ft_strdup(line);
		printf("%s\n", "super piece");
		if (data->piece.curent == (data->piece.y - 1))
			data->status |= OPT_PIECE_FULL;
		data->piece.curent++;
	}
}