/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gml.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:30:09 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/17 19:26:48 by mlemee           ###   ########.fr       */
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

	printf("FILL STA IN\n\n");
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
	{
		printf("MALLOC FILL_STA1 ERROR\n\n");
		return (NULL);
	}
	while (!ft_strchr(sta, '\n'))
	{
		printf("BOUCLE STA IN \n\n\n");
		endbuf = read(fd, buf, BUFFER_SIZE) + 1;
		if (endbuf <= 0)
		{
			printf("ENDBUF FILL_STA1 ERROR\n\n");
			return (NULL);
		}
		buf[endbuf] = '\0';
		printf("STRJOIN TESST \n\n\n");
		sta = ft_strjoin(sta, buf);
		printf("STRJOIN OK \n\n\n");
		if (sta == NULL)
		{
			printf("JOIN STA FILL_STA1 ERROR\n\n");
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

	sta == NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	sta = ft_fill_sta(sta, fd);
	if (!sta)
	{
		printf("ERREUR FILL_STA\n\n");
		return (NULL);
	}
	line = ft_fill_line(sta);
	if (!line)
	{
		printf("ERREUR FILL_LINE\n\n");
		return (NULL);
	}
	sta = ft_new_sta(sta, line);
	if (!sta)
	{
		printf("ERREUR FILL_STA22222\n\n");
		return (NULL);
	}
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