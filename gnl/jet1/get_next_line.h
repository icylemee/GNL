/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemee <mlemee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:50:40 by mlemee            #+#    #+#             */
/*   Updated: 2025/05/17 18:57:07 by mlemee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H 

//# define BUFFER_SIZE    1024
# include <stdlib.h>
#include <unistd.h>


char	*ft_strjoin(char const *s1, char const *s2);
ssize_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif