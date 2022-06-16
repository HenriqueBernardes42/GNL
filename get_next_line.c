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

char *current_line(int fd, char *str)
{
	int i;
	char		*buffer;

	i = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while(!there_it_is(str, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return str;
}

char *get_next_line(int fd)
{
	char *str;

	// if(str == NULL)
	// 	str = ft_strdup("");
	// printf("str = |%s|\n",str);
	str = current_line(fd, str);
	return str;
}