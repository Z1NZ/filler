#include "filler.h"


void	get_piece(t_data *data, char *line)
{
	if (ft_strstr(line, "Piece"))
	{
		data->status |= OPT_PLATEAU_SET;
		if ((tmp = ft_strchr(line , ':')))  /// a faire 
			*tmp = ' ';
		tab = ft_strsplit(line, ' ');
		if (!check_digit(tab[1]))
			ft_error();
		if (!check_digit(tab[2]))
			ft_error();
		data->piece.x = ft_atoi(tab[2]);
		data->piece.y = ft_atoi(tab[1]);
		data->piece.map = ft_memalloc(sizeof(char *) * data->piece.y);
	}
}
int main(int argc, char **argv)
{
	t_data	*data;
	char	*line;

	(void)argc;
	data = ft_memalloc(sizeof(t_data));
	while(0xDEADBEEF)
	{
		if (get_next_line(0, &line))
		{	
			if (!CHECK_BIT(data->status, OPT_PLAYER_SET))
				get_player(data, line, *argv);
			else if (!CHECK_BIT(data->status, OPT_MAP_SET))
				get_set_map(data, line);
			else if (CHECK_BIT(data->status, OPT_MAP_SET) && CHECK_BIT(data->status, OPT_PLAYER_SET) && data->curent <= data->y)
				get_map(data, line);
			else if (!CHECK_BIT(data->status, OPT_PIECE_SET))
				get_piece(data, line)
			free(line);
		}
	}
	return 0;
}