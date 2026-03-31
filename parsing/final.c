/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:42:49 by shassoun          #+#    #+#             */
/*   Updated: 2025/05/05 17:13:11 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_tab(int *tab)
{
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	tab[5] = 0;
	tab[6] = 0;
	tab[0] = 0;
}

void	pars_the_map(char **map, t_map *param)
{
	int	i;
	int	j;
	int	tab[7];

	j = 0;
	initialize_tab(tab);
	while (map[j] && check_all_para_are_loaded(tab) != 1)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == ' ')
				i++;
			direction(map[j], tab, param, &i);
			color(map[j], tab, param, &i);
			if (map[j][i])
				i++;
		}
		j++;
	}
	if (map[j] && check_all_para_are_loaded(tab) == 1)
		pars_map(map, j, param);
	if (check_all_para_are_loaded(tab) == 0)
		_write(2, "Missing parameter\n", 18, param);
}

t_map	*parsing(int argc, char **argv)
{
	t_map	*param;
	char	**map;

	if (argc != 2)
	{
		ft_putstr_fd("Wrong numbers of arguments\n", 2);
		exit(1);
	}
	param = malloc(sizeof(t_map));
	map = get_map(argv[1], param);
	param->map = map;
	param->map_width_rows = NULL;
	pars_the_map(map, param);
	return (param);
}
