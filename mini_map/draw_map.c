/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:27:40 by asabir            #+#    #+#             */
/*   Updated: 2025/05/07 00:45:54 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_square(t_parameters *parameters, double x, double y, int color)
{
	double	i;
	double	j;

	j = 0;
	while (j < parameters->tilesize * parameters->minimap_factor)
	{
		i = 0;
		while (i < parameters->tilesize * parameters->minimap_factor)
		{
			my_mlx_pixel_put(parameters, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	check_case(t_parameters *par, int x, int y)
{
	if (par->map[y][x] == '1')
	{
		draw_square(par, scale1(0, par->map_width * par->tilesize
				* par->minimap_factor, x, par->map_width), scale1(0,
				par->map_height * par->tilesize * par->minimap_factor, y,
				par->map_height), 0x0FFFFFF);
	}
	else if (par->map[y][x] == '0')
		draw_square(par, scale1(0, par->map_width * par->tilesize
				* par->minimap_factor, x, par->map_width), scale1(0,
				par->map_height * par->tilesize * par->minimap_factor, y,
				par->map_height), 0x0000000);
}

void	draw_map(t_parameters *par)
{
	int	x;
	int	y;

	y = 0;
	while (par->map[y])
	{
		x = 0;
		while (par->map[y][x])
		{
			check_case(par, x, y);
			x++;
		}
		y++;
	}
	draw_circle(par);
	mlx_put_image_to_window(par->connection, par->window, par->img, 0, 0);
}

void	get_map_information(t_parameters *parameters)
{
	int	j;
	int	buff_size;

	j = 0;
	parameters->map_width = 0;
	parameters->map_height = 0;
	while (parameters->map[j])
	{
		if (j == 0)
			parameters->map_width = ft_strlen(parameters->map[j]);
		else
		{
			buff_size = ft_strlen(parameters->map[j]);
			if (buff_size > parameters->map_width)
				parameters->map_width = buff_size;
		}
		j++;
	}
	parameters->map_height = j;
}
