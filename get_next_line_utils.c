#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((dst[i]) && (i < size))
		++i;
	while ((src[j]) && (j + i + 1 < size))
	{
		dst[i + j] = src[j];
		++j;
	}
	if (i < size)
		dst[j + i] = '\0';
	return (i + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			size1;
	int			size2;
	char		*ptr;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	ptr = calloc((size1 + size2 + 2) , sizeof(char));
	if (ptr != NULL )
	{
		ft_strlcat(ptr, s1, size1 + 1);
		ft_strlcat(ptr, s2, size1 + size2 + 1);
		ptr[size1 + size2 + 1] = '\0';
		return (ptr);
	}
	else
		return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	dest = calloc((size + 1) , sizeof(char));
	while (s[i])
	{
		dest[i] = s[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
