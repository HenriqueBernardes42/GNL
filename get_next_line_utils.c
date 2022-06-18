#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}



char	*ft_strjoin(char *s1, char *s2)
{
	char 	*new;
	size_t	total_size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if(!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	total_size = ft_strlen(s1) + ft_strlen(s2);
	new = calloc((total_size + 1) , sizeof(char));
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
	free(s1); //<-libera o antigo str, que agora é new
	return new;
}
