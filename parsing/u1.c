/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:42:30 by shassoun          #+#    #+#             */
/*   Updated: 2025/05/24 23:49:35 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_player(char *line, t_map *param, int j, int *flag)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'E' || line[i] == 'W' || line[i] == 'S'
			|| line[i] == 'N')
		{
			param->direction = line[i];
			param->player[0] = i;
			param->player[1] = j;
			(*flag)++;
		}
		else if (line[i] != ' ' && line[i] != '0' && line[i] != '1')
			_write(2, "Invalid character\n", 18, param);
		i++;
	}
}

int	whach_ghi_lvalid_chars(char **map, t_map *param)
{
	int	flag;
	int	j;

	flag = 0;
	j = 0;
	while (map[j])
	{
		check_player(map[j], param, j, &flag);
		j++;
	}
	param->map_height = j;
	param->map_width_rows = malloc((param->map_height) * sizeof(int));
	if (flag != 1)
		_write(2, "ERROR:Multiple players, or no player\n", 38, param);
	return (1);
}

int	closed_map_suit(char **map, int i, int j, t_map *param)
{
	if (((map[j + 1] && (int)ft_strlen(map[j + 1]) <= i)) || (j > 0 && map[j
				- 1] && (int)ft_strlen(map[j - 1]) <= i))
		return (_write(2, "the map is not closed!\n", 24, param), exit(1), 1);
	if ((j == 0) || (map[j + 1] == NULL) || (j > 0 && map[j - 1] && map[j
				- 1][i] && map[j - 1][i] == ' ') || (j > 0 && map[j + 1]
					&& map[j
			+ 1][i] && map[j + 1][i] == ' '))
		return (_write(2, "the map is not closed!\n", 24, param), exit(1), 1);
	return (0);
}

int	whach_lmap_msdoda(char **map, t_map *param)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '0' || map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'E' || map[j][i] == 'W')
			{
				if (i == 0 || (map[j][i + 1] && (map[j][i + 1] == ' '))
					|| (map[j][i + 1] == '\0') || (i > 0 && map[j][i
						- 1] && map[j][i - 1] == ' '))
					return (_write(2, "the map is not closed!\n", 24, param),
						exit(1), 1);
				closed_map_suit(map, i, j, param);
			}
		}
		param->map_width_rows[j] = i;
		j++;
	}
	return (0);
}

void	pars_map(char **map, int j, t_map *param)
{
	param->map_only = map + j;
	whach_ghi_lvalid_chars(param->map_only, param);
	whach_lmap_msdoda(param->map_only, param);
}
