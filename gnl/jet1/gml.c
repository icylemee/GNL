/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gml.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:30:09 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/17 18:56:40 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 1


char	*ft_fill_sta(char *sta, int fd)
{
	ssize_t	endbuf;
	char	*buf;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(sta, '\n') && endbuf == BUFFER_SIZE)
	{
		endbuf = read(fd, buf, BUFFER_SIZE);
		if (endbuf <= 0)
			return (NULL);
		buf[endbuf] = '\0';
		sta = ft_strjoin(sta, buf);
		if (sta == NULL)
		{
			free(sta);
			return (NULL);
		}
	}
	free(buf);
	return (sta);
}

char	*ft_fill_line(char *sta)
{
	char	*line;
	int		i;

	i = 0;
	while (sta[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (sta[i] && sta[i] != '\n')
	{
		line[i] = sta[i];
		i++;
	}
	if (sta[i] == '\n')
		line[i] = sta[i];
	line[i] = '\0';
	return (line);
}

char	*ft_new_sta(char *sta, char *line)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (sta[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (ft_strlen(sta) + 1 - i));
	if (!new)
	{
		free(sta);
		free(line);
		return (NULL);
	}
	i++;
	while (sta[i])
	{
		new[j] = sta[i];
		i++;
	}
	free(sta);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*sta;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	sta = ft_fill_sta(sta, fd);
	if (!sta)
		return (NULL);
	line = ft_fill_line(sta);
	sta = ft_new_sta(sta, line);
	free(line);
	return (line);
}
int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *s = get_next_line(fd);
	if (s == NULL)
	{
		printf("erreur");
		return (0);
	}
	
	printf("%s\n\n", get_next_line(fd));
	
	// while (get_next_line(fd))
	// {
	// 	printf("%s\n\n", get_next_line(fd));
	// }
}