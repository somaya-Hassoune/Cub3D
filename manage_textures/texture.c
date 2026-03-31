/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:36:12 by shassoun          #+#    #+#             */
/*   Updated: 2025/05/07 14:23:45 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	get_texture_color(void *texture, int x, int y)
{
	int		*data;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;

	if (!texture)
		return (0xFFFFFF);
	addr = mlx_get_data_addr(texture, &bpp, &size_line, &endian);
	data = (int *)addr;
	return (data[y * (size_line / (bpp / 8)) + x]);
}

void	coloring_ciel(int start, int end, int x, t_parameters *par)
{
	int	j;

	j = 0;
	while ((start + j) < end)
	{
		if (is_that_2d(x, start + j, par) == 0)
			my_mlx_pixel_put(par, x, start + j,
				(double)(rgb_to_hex(par->c_clr[0], par->c_clr[1],
						par->c_clr[2]))*0.5);
		j++;
	}
}

void	coloring_floor(int start, int end, int x, t_parameters *par)
{
	int	j;

	j = 0;
	while ((start + j) < end)
	{
		if (is_that_2d(x, start + j, par) == 0)
			my_mlx_pixel_put(par, x, start + j,
				(double)(rgb_to_hex(par->f_clr[0], par->f_clr[1],
						par->f_clr[2]))*0.5);
		j++;
	}
}

void	coloring_wall(int arg[3], t_parameters *par, void *texture,
		int wall_height)
{
	int	j;
	int	texture_x;
	int	texture_y;
	int	color;

	j = arg[0];
	while (j < arg[1])
	{
		if (par->rayc->casted_rays[arg[2]].is_vertical)
			texture_x = (int)par->rayc->casted_rays[arg[2]].y_hit
				% (int)par->tilesize;
		else
			texture_x = (int)par->rayc->casted_rays[arg[2]].x_hit
				% (int)par->tilesize;
		texture_y = (int)((j - arg[0]) * par->tilesize / wall_height);
		color = get_texture_color(texture, texture_x, texture_y);
		if (is_that_2d(arg[2], j, par) == 0)
			my_mlx_pixel_put(par, arg[2], j, color);
		j++;
	}
}

void	draw_wall(t_parameters *par, int x, int wall_height)
{
	int		start_y;
	int		end_y;
	void	*texture;
	int		arg[3];

	start_y = par->screen_height / 2 - wall_height / 2;
	end_y = start_y + wall_height;
	coloring_ciel(0, start_y, x, par);
	coloring_floor(end_y, par->screen_height, x, par);
	if (par->rayc->casted_rays[x].is_vertical)
	{
		if (par->rayc->casted_rays[x].x_hit > par->player->x)
			texture = par->ea_texture;
		else
			texture = par->we_texture;
	}
	else
	{
		if (par->rayc->casted_rays[x].y_hit > par->player->y)
			texture = par->so_texture;
		else
			texture = par->no_texture;
	}
	coloring_wall(full_arg(arg, start_y, end_y, x), par, texture, wall_height);
}
