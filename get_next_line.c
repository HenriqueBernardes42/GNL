#include "get_next_line.h"

int there_it_is(char *str, int find)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(str[i] == find)
			return 1;
		++i;
	}
	return 0;
}

char *get_next_line(int fd)
{
	char		*str;
	char		*buffer;
	char		*dest;
	static int			i;

	i = 1;
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	while(!there_it_is(str, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		str = ft_strjoin(str, buffer);
	}
	i = 0;
	while(str[i] != '\n'))
		++i;

	dest = ft_substr(str, )

	free(buffer);
	return (str);
}