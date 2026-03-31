/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:42:37 by shassoun          #+#    #+#             */
/*   Updated: 2025/05/03 14:42:38 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_the_2chars(char *str, int i)
{
	if (!str[i] || !str[i + 1] || !str[i + 2])
		return (0);
	if (str[i + 2] != ' ')
		return (0);
	if (i != 0 && str[i - 1] != ' ')
		return (0);
	if (str[i] == 'N' && str[i + 1] == 'O')
		return (NO);
	if (str[i] == 'S' && str[i + 1] == 'O')
		return (SO);
	if (str[i] == 'W' && str[i + 1] == 'E')
		return (WE);
	if (str[i] == 'E' && str[i + 1] == 'A')
		return (EA);
	return (0);
}

int	check_the_colors(char *str, int i)
{
	if (!str[i] || !str[i + 1])
		return (0);
	if (str[i + 1] != ' ')
		return (0);
	if (i != 0 && str[i - 1] != ' ')
		return (0);
	if (str[i] == 'F')
		return (F);
	if (str[i] == 'C')
		return (C);
	return (0);
}

int	check_xpm(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len <= 3)
		return (1);
	if (str[len - 1] == 'm' && str[len - 2] == 'p' && str[len - 3] == 'x'
		&& str[len - 4] == '.')
		return (0);
	else
		return (1);
}

void	direction(char *line, int *tab, t_map *param, int *i)
{
	int	val;
	int	start;

	val = check_the_2chars(line, (*i));
	if (line[*i] && val != 0)
	{
		(*i) += 2;
		while (line[*i] == ' ')
			(*i)++;
		start = *i;
		while (line[*i] && line[*i] != ' ')
		{
			param->textures[val - 1][*i - start] = line[*i];
			(*i)++;
		}
		param->textures[val - 1][*i - start] = '\0';
		while (line[*i] == ' ')
			(*i)++;
		if (line[*i] != '\0' || check_xpm(param->textures[val - 1]) != 0)
			_write(2, "structure ghalat\n", 18, param);
		if (tab[val] == 0)
			tab[val] = 1;
		else
			_write(2, "1joj les parameter m3awdin\n", 27, param);
	}
}

void	color(char *line, int *tab, t_map *param, int *i)
{
	int	val;

	val = 0;
	val = check_the_colors(line, *i);
	if (line[*i] && val != 0)
	{
		(*i)++;
		while (line[*i] == ' ')
			(*i)++;
		get_numbers_rgb(line, *i, param, val);
		if (tab[val] == 0)
			tab[val] = 1;
		else
			_write(2, "2joj les parameter m3awdin\n", 27, param);
	}
}
