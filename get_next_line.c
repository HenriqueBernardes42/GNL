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

char *left_str(char *remainder)
{
	char *str;
	str = ft_strdup(remainder);
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
	remainder = ft_substr(str, i + 1, str_size);
	dest = calloc(i + 1, sizeof(char));
	while(j <= i)
	{
		dest[j] = str[j];
		++j;
	}
	free(str);
	str = left_str(remainder);
	free(remainder);
	return (dest);
}