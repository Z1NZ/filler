#include "filler.h"

int		check_piece(char *line)
{
	if (*line != '\0')
	{
		while(*line == '.' || *line == '*')
			line++;
		if (*line == '\0')
			return(1);
		else
			return(0);
		
	}
	else 
		return(0);
}