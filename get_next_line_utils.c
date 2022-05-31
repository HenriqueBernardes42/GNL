#include "get_next_line.h"

void call_gnl()
{
	int		i;

	i = 0;
	while(i < 3)
	{
		get_next_line(1);
		printf("\n\n");
		++i;
	}
}