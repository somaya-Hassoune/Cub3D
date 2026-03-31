/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:58:13 by asabir            #+#    #+#             */
/*   Updated: 2025/05/06 23:58:57 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
// # include <stdio.h>
// # include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_calloc(size_t numelement, size_t elementsize);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char **s1, char *s2);
size_t	ft_strlen(char *str);
void	*ft_memset(void *b, int x, size_t len);
char	*get_next_line(int fd);

#endif