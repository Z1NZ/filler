#include "filler.h"

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
			{
				printf("%s\n", "get_player");
				get_player(data, line, *argv);
			}
			else if (!CHECK_BIT(data->status, OPT_PLATEAU_SET))
			{
				printf("%s\n", "get_set_map");
				get_set_map(data, line);
			}
			else if (CHECK_BIT(data->status, OPT_PLATEAU_SET) && !CHECK_BIT(data->status, OPT_MAP_SET))
			{

				printf("%s current -> [%d] size -> [%d]\n", "get_map", data->curent, data->y);
				get_map(data, line);
			}
			else if (!CHECK_BIT(data->status, OPT_PIECE_SET))
			{
				printf("%s\n", "get_set_piece");
				get_set_piece(data, line);
			}
			else if (CHECK_BIT(data->status, OPT_PIECE_SET) && !CHECK_BIT(data->status, OPT_PIECE_FULL))
			{
				printf("%s curent [%d]   size[%d]\n", "get_piece", data->piece.curent, data->piece.y);
				get_piece(data, line);
			}
			else
			{
				printf("%s\n", "SUPER commando_para");
				commando_para(data);
			}
				// debug(data);
			free(line);
		}
	}
	return 0;
}
