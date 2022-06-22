/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:42:43 by hbernard          #+#    #+#             */
/*   Updated: 2022/06/22 23:21:08 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buffer, size_t i, size_t j)
{
	char	*new_str;

	if (!str)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buffer)) + 1));
	if (new_str == NULL)
		return (NULL);
	if (str)
	{
		while (str[i] != '\0')
		{
			new_str[i] = str[i];
			++i;
		}
	}
	while (buffer[j] != '\0')
		new_str[i++] = buffer[j++];
	new_str[ft_strlen(str) + ft_strlen(buffer)] = '\0';
	free(str);
	return (new_str);
}
