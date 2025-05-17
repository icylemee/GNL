/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:50:27 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/17 19:25:16 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lt;
	char	*new;
	int		i;
	int		j;

	printf("STRJOIN IN\n\n");
	lt = ft_strlen(s1) + ft_strlen(s2) + 1;
	printf("LT STRJOIN OK\n\n");
	new = malloc(lt * sizeof(char));
	if (new == NULL)
	{
		printf("MALLOC STRJOIN ERROR\n\n");
		return (NULL);
	}
	i = 0;
	printf("AVANT WHILE 1\n\n");
	if (s1 != NULL)
	{
		printf("ENTREE CONDI SECURE AVANT WHILE 1\n\n");
		while (s1[i])
		{
			printf("ENTREE WHILE 1\n\n");
			new[i] = s1[i];
			i ++;
		}
	}
	printf("WHILE 1 STRJOIN OK\n\n");
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		i ++;
		j++;
	}
	printf("WHILE 2 STRJOIN OK\n\n");
	new[i] = '\0';
	return (new);
}

ssize_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

