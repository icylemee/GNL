/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:24:27 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/17 17:23:53 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 1024
#include "get_next_line.h"



char 
char	*get_next_line(int fd)
{
	char		*line;
	static char	*sta;
	char		*buf;
	int			n;
	ssize_t		r;

	buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (r)
	{
		r = read(fd, buf, BUFFER_SIZE);
		sta = malloc(sizeof(char) * ft_strlen(buf));
		n = ft_search_n(sta);

	}
}

int	ft_search_n(char *sta)
{
	int	i;

	i = 0;
	while (sta[i])
	{
		if (sta[i] == '\n')
			break ;
		i ++;
	}
	if (sta[i] == '\n')
	{
		
	}
	return (i);
}

char	*ft_fill_line(char *sta)
{
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = ft_search_n(sta);
	line = malloc(sizeof(char) * len);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = sta[i];
		i ++;
	}
}

