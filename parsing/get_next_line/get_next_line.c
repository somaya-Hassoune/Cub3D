/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:58:17 by asabir            #+#    #+#             */
/*   Updated: 2025/05/06 23:58:34 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_line_again(char *line)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
	{
		i++;
	}
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	if (line[i] == '\n')
		i++;
	res = malloc(ft_strlen(line) - i + 1);
	if (!res)
		return (NULL);
	while (line[i])
		res[j++] = line[i++];
	res[j] = '\0';
	free(line);
	return (res);
}

static char	*set_return(char *line)
{
	int		i;
	int		a;
	char	*str;

	i = 0;
	a = 0;
	if (!line || !line[i])
		return (NULL);
	while (line[i] != '\n' && line[i])
	{
		i++;
	}
	if (line[i] == '\n')
		i++;
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	while (a < i)
	{
		str[a] = line[a];
		a++;
	}
	str[i] = '\0';
	return (str);
}

static char	*free_(char **line, char **buff)
{
	free(*line);
	free(*buff);
	return (NULL);
}

static char	*get_ligne(int fd, char *line)
{
	char	*buff;
	int		b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	b = 1;
	while (!ft_strchr(line, '\n'))
	{
		buff = (char *)malloc(BUFFER_SIZE * (sizeof(char) + 1));
		b = read(fd, buff, BUFFER_SIZE);
		if (b < 0)
			return (free_(&line, &buff));
		if (b == 0)
		{
			free(buff);
			break ;
		}
		buff[b] = '\0';
		line = ft_strjoin(&line, buff);
		free(buff);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*str;

	line = get_ligne(fd, line);
	if (!line)
	{
		return (NULL);
	}
	str = set_return(line);
	line = set_line_again(line);
	return (str);
}
