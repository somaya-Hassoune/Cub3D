/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:27:47 by asabir            #+#    #+#             */
/*   Updated: 2025/05/24 23:38:41 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	check_if_there_is_a_wall(t_parameters *par, double x, double y)
{
	int	old_x;
	int	old_y;
	int	map_x;
	int	map_y;

	map_x = (int)(x / par->tilesize);
	map_y = (int)(y / par->tilesize);
	old_x = (int)(par->player->x / par->tilesize);
	old_y = (int)(par->player->y / par->tilesize);
	if (map_y < 0 || map_y >= par->map_height)
		return (1);
	if (map_x < 0 || map_x >= par->map_width_rows[map_y])
		return (1);
	if (par->map[map_y][map_x] == '1')
		return (1);
	else if (map_x != old_x && map_y != old_y)
	{
		if (par->map[map_y][old_x] == '1'
			&& par->map[old_y][map_x] == '1')
			return (2);
	}
	return (0);
}

void	draw_line_helper(double step, double delta_x, double delta_y,
		t_parameters *par)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	x = par->player->x;
	y = par->player->y;
	while (i < step)
	{
		my_mlx_pixel_put(par, x * par->minimap_factor, y * par->minimap_factor,
			0xFFF400);
		x += delta_x;
		y += delta_y;
		i++;
	}
}

void	draw_line(t_parameters *par, char check)
{
	double	delta_x;
	double	delta_y;
	double	step;
	double	x_end;
	double	y_end;

	if (check == 'v')
	{
		x_end = par->rayc->v_x_intersec;
		y_end = par->rayc->v_y_intersec;
	}
	else
	{
		x_end = par->rayc->h_x_intersec;
		y_end = par->rayc->h_y_intersec;
	}
	delta_x = x_end - par->player->x;
	delta_y = y_end - par->player->y;
	step = fmax(fabs(delta_x), fabs(delta_y));
	delta_x /= step;
	delta_y /= step;
	draw_line_helper(step, delta_x, delta_y, par);
}

void	draw_circle(t_parameters *par)
{
	double	x;
	double	y;

	par->player->radius = 10;
	y = par->player->y - par->player->radius;
	while (y <= par->player->y + par->player->radius)
	{
		x = par->player->x - par->player->radius;
		while (x <= par->player->x + par->player->radius)
		{
			if ((pow(x - par->player->x, 2) + pow(y - par->player->y,
						2)) <= par->player->radius * par->player->radius)
			{
				my_mlx_pixel_put(par, x * par->minimap_factor, y
					* par->minimap_factor, 0xFF00FF);
			}
			x++;
		}
		y++;
	}
	reflect_ray(par);
	the_3d_projection(par);
}
