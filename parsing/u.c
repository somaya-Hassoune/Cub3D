/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:42:23 by shassoun          #+#    #+#             */
/*   Updated: 2025/05/05 17:08:44 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_param(t_map *param)
{
	int	j;

	j = 0;
	while ((param->map)[j] != NULL)
	{
		free(param->map[j]);
		j++;
	}
	free(param->map);
	if (param->map_width_rows != NULL)
		free(param->map_width_rows);
	free(param);
}

void	_write(int fd, char *str, int line, t_map *param)
{
	write(fd, str, line);
	free_param(param);
	exit(1);
}

int	check_all_para_are_loaded(int *tab)
{
	int	i;

	i = 1;
	while (i <= 6)
	{
		if (tab[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void	get_num(char num[4], char *line, int *i, t_map *param)
{
	int	start;

	start = 0;
	num[0] = '\0';
	num[1] = '\0';
	num[2] = '\0';
	num[3] = '\0';
	start = *i;
	if (!(line[*i] >= '0' && line[*i] <= '9'))
		_write(2, "Colors problem\n", 15, param);
	while (line[*i] >= '0' && line[*i] <= '9' && (*i) - start < 3)
	{
		num[*i - start] = line[*i];
		(*i)++;
	}
	if ((*i) - start > 3)
		_write(2, "Colors problem\n", 15, param);
}

void	get_numbers_rgb(char *line, int i, t_map *param, int val)
{
	int		count_number;
	char	num[4];

	count_number = 0;
	while (line[i] && line[i] != ' ')
	{
		get_num(num, line, &i, param);
		if (line[i] != ',' && count_number < 2)
			_write(2, "Colors problem\n", 15, param);
		if (count_number == 2 && (line[i] != ' ' && line[i] != '\0'))
			_write(2, "Colors problem\n", 15, param);
		if (line[i] == ',')
			i++;
		if (val == F)
			param->f_color[count_number] = ft_atoi(num, param);
		if (val == C)
			param->c_color[count_number] = ft_atoi(num, param);
		count_number++;
	}
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
		_write(2, "Wrong struct\n", 13, param);
}
