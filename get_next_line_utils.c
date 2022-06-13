#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;
	size_t		s_len;

	i = 0;
	s_len = ft_strlen(s);
	if ((s_len - start) < s_len)
		s_len = s_len - start;
	if (len < s_len)
		s_len = len;
	ptr = (char*) malloc((s_len + 1) * sizeof(char));
	if (ptr != NULL)
	{
		while (i < len && s[start])
		{
			ptr[i] = s[start];
			++start;
			++i;
		}
		return (ptr);
	}
	return (NULL);
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
	ptr = malloc((size1 + size2 + 1) * sizeof(char));
	if (ptr != NULL )
	{
		ft_strlcat(ptr, s1, size1 + 1);
		ft_strlcat(ptr, s2, size1 + size2 + 1);
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
	dest = malloc((size + 1) * sizeof(char));
	while (s[i])
	{
		dest[i] = s[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = c;
		++i;
	}
	return (s);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}