/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:27:57 by asabir            #+#    #+#             */
/*   Updated: 2025/05/14 16:40:56 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	case_infinit_tan(t_parameters *par)
{
	par->rayc->h_y_intersec = par->player->y;
	par->rayc->h_x_intersec = par->player->x;
	return (10000);
}

double	find_horizontal_intersections_and_raylength(t_parameters *par,
		int inside_cell, double delta_x, double delta_y)
{
	double	ray_length;

	if (par->player->facing_up)
		delta_y = -par->tilesize;
	else
		delta_y = par->tilesize;
	delta_x = delta_y / tan(par->player->dir_angle);
	while (check_if_there_is_a_wall(par, par->rayc->h_x_intersec,
			par->rayc->h_y_intersec - inside_cell) != 1)
	{
		par->rayc->h_x_intersec += delta_x;
		par->rayc->h_y_intersec += delta_y;
	}
	ray_length = sqrt(pow(par->player->x - par->rayc->h_x_intersec, 2)
			+ pow(par->player->y - par->rayc->h_y_intersec, 2));
	return (ray_length);
}

double	horizontal_intersections(t_parameters *par)
{
	double	delta_y;
	double	delta_x;
	double	inside_cell;

	inside_cell = 0;
	delta_y = 0;
	delta_x = 0;
	if (sin(par->player->dir_angle) >= -0.00000000001
		&& sin(par->player->dir_angle) <= 0.00000000001)
		return (case_infinit_tan(par));
	if (par->player->facing_up)
	{
		inside_cell = 1;
		par->rayc->h_y_intersec = floor((par->player->y) / par->tilesize)
			* par->tilesize;
	}
	else
		par->rayc->h_y_intersec = ceil(par->player->y / par->tilesize)
			* par->tilesize;
	par->rayc->h_x_intersec = (par->rayc->h_y_intersec - par->player->y)
		/ tan(par->player->dir_angle) + par->player->x;
	return (find_horizontal_intersections_and_raylength(par, inside_cell,
			delta_x, delta_y));
}

double	find_vertical_intersections_and_raylength(t_parameters *par,
		int inside_cell, double delta_x, double delta_y)
{
	double	ray_length;

	if (par->player->facing_right)
		delta_x = par->tilesize;
	else
		delta_x = -par->tilesize;
	delta_y = delta_x * tan(par->player->dir_angle);
	while (check_if_there_is_a_wall(par, par->rayc->v_x_intersec - inside_cell,
			par->rayc->v_y_intersec) != 1)
	{
		par->rayc->v_x_intersec += delta_x;
		par->rayc->v_y_intersec += delta_y;
	}
	ray_length = sqrt(pow(par->player->x - par->rayc->v_x_intersec, 2)
			+ pow(par->player->y - par->rayc->v_y_intersec, 2));
	return (ray_length);
}

double	vertical_intersections(t_parameters *par)
{
	double	delta_y;
	double	delta_x;
	double	inside_cell;

	inside_cell = 0;
	delta_y = 0;
	delta_x = 0;
	if (cos(par->player->dir_angle) >= -0.00000000001
		&& cos(par->player->dir_angle) <= 0.00000000001)
		return (case_infinit_tan(par));
	if (par->player->facing_right)
		par->rayc->v_x_intersec = ceil(par->player->x / par->tilesize)
			* par->tilesize;
	else
	{
		inside_cell = 1;
		par->rayc->v_x_intersec = floor((par->player->x) / par->tilesize)
			* par->tilesize;
	}
	par->rayc->v_y_intersec = (par->rayc->v_x_intersec - par->player->x)
		* tan(par->player->dir_angle) + par->player->y;
	return (find_vertical_intersections_and_raylength(par, inside_cell, delta_x,
			delta_y));
}
