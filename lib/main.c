#include "filler.h"

int main()
{

	char *line;

	while(get_next_line(0, &line) > 0)
	{
		printf("[%s\n]", line);
	}
	return 0;
}