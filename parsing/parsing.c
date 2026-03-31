/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:42:42 by shassoun          #+#    #+#             */
/*   Updated: 2025/05/08 12:52:43 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_write_(int fd, char *str, int line, t_map *param)
{
	write(fd, str, line);
	free(param);
	exit(1);
}

char	*read_from_file(char *filename, t_map *par)
{
	int		x;
	char	*str;
	char	*map_str;
	int		len;

	len = ft_strlen(filename);
	if (len < 5 || (filename[len - 1] != 'b' || filename[len - 2] != 'u'
			|| filename[len
				- 3] != 'c' || filename[len - 4] != '.'))
		free_write_(2, "Adjust the file name please :)\n", 31, par);
	x = open(filename, O_RDONLY);
	if (x == -1)
		free_write_(2, "The file is not valid\n", 22, par);
	str = get_next_line(x);
	map_str = malloc(1);
	map_str[0] = '\0';
	while (str)
	{
		map_str = ft_strjoin(&map_str, str);
		free(str);
		str = get_next_line(x);
	}
	close(x);
	return (map_str);
}

char	**get_map(char *file, t_map *par)
{
	char	*str;
	char	**map;

	str = NULL;
	map = NULL;
	str = read_from_file(file, par);
	map = ft_split(str, '\n');
	free(str);
	return (map);
}
