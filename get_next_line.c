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
	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	while(!there_it_is(buffer, '\n') && i != 0)
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
	static char		*str;
	char		*remainder;
	char		*dest;
	int			i;
	int			j;
	size_t		str_size;

	j = 0;
	i = 0;
	if(str == NULL)
		str = ft_strdup("");
	str = current_line(fd, str);
	str_size = ft_strlen(str);
	while(str[i] != '\n' && str[i] != '\0')
		++i;
	if((str_size - i) > 1)
	{
		remainder = malloc((str_size - i) * sizeof(char));
		++i;
		while((size_t) i < str_size)
		{
			remainder[j] = str[i];
			++i;
		}
		remainder[j] = '\0';
	}
	else
		remainder = ft_strdup("");
	dest = calloc((i + 2) , sizeof(char));
	while(j <= i)
	{
		dest[j] = str[j];
		++j;
	}
	str = ft_strdup(remainder);
	free(remainder);
	return (dest);
}