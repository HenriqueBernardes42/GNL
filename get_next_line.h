/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbernard <hbernard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:21:24 by hbernard          #+#    #+#             */
/*   Updated: 2022/06/23 06:23:33 by hbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<stdlib.h>
# include	<unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *str, char *buffer);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);
#endif
