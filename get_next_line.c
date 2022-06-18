#include "get_next_line.h"

int there_it_is(char *s, int c)
{
	int		position;

	position = 0;
	if (!s)
		return (0);
	while (s[position])
	{
		if (s[position] == c)
			return position;
		++position;
	}
	return (0);
}

char *new_str(char *str,int i,int j)
{
	char	*reminder;

	while(str[i])
		++i;
	reminder = calloc((i - j + 1) , sizeof(char));
	i = 0;
	while(str[j])
		reminder[i++] = str[j++];
	free(str);
	return reminder;
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;
	int			i;
	int			j;

	i = -1;
	buffer = calloc((BUFFER_SIZE + 1) , sizeof(char));
	while(!there_it_is(buffer, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	j = 0;
	i = 0;
	while(str[j] != '\n' && str[j] != '\0')
		++j;
	++j;
	line = calloc((j + 1) , sizeof(char));
	while(i < j)
	{
		line[i] = str[i];
		++i;
	}
	str = new_str(str, i, j);
	free(buffer);
	return line;
}