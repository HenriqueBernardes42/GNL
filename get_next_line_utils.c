#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char 	*new;
	size_t	total_size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	// printf("total_size = %ld\n", total_size);
	new = malloc((total_size + 1) * sizeof(char));
	while(s1[i])
	{
		new[i] = s1[i];
		++i;
	}
	while(s2[j])
	{
		new[i + j] = s2[j];
		++j;
	}

	return new;
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	dest = malloc((size + 1) * sizeof(char));
	while (s[i])
	{
		dest[i] = s[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
