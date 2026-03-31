/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:07:43 by asabir            #+#    #+#             */
/*   Updated: 2025/05/08 13:29:04 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_direction_informations(t_parameters *par)
{
	if (sin(par->player->dir_angle) > 0)
		par->player->facing_up = 0;
	else
		par->player->facing_up = 1;
	if (cos(par->player->dir_angle) > 0)
		par->player->facing_right = 1;
	else
		par->player->facing_right = 0;
}

void	store_wall_hit_information(double v_ray_length, double h_ray_length,
		t_parameters *par, int ray_index)
{
	if (v_ray_length < h_ray_length)
	{
		par->rayc->casted_rays[ray_index].distance = v_ray_length;
		par->rayc->casted_rays[ray_index].is_vertical = 1;
		par->rayc->casted_rays[ray_index]
			.casted_ray_rotation_angle = par->player->dir_angle;
		par->rayc->casted_rays[ray_index].x_hit = par->rayc->v_x_intersec;
		par->rayc->casted_rays[ray_index].y_hit = par->rayc->v_y_intersec;
		draw_line(par, 'v');
	}
	else
	{
		par->rayc->casted_rays[ray_index].distance = h_ray_length;
		par->rayc->casted_rays[ray_index].is_vertical = 0;
		par->rayc->casted_rays[ray_index]
			.casted_ray_rotation_angle = par->player->dir_angle;
		par->rayc->casted_rays[ray_index].x_hit = par->rayc->h_x_intersec;
		par->rayc->casted_rays[ray_index].y_hit = par->rayc->h_y_intersec;
		draw_line(par, 'h');
	}
}

void	reflect_ray(t_parameters *par)
{
	double	v_ray_length;
	double	h_ray_length;
	double	end_fov;
	int		ray_index;
	double	step_angle;

	ray_index = 0;
	step_angle = par->player->fov / par->screen_width;
	par->current_angle = par->player->dir_angle;
	end_fov = par->player->dir_angle + par->player->fov / 2;
	par->player->dir_angle = par->player->dir_angle - par->player->fov / 2;
	while (par->player->dir_angle < end_fov)
	{
		set_direction_informations(par);
		v_ray_length = vertical_intersections(par);
		h_ray_length = horizontal_intersections(par);
		store_wall_hit_information(v_ray_length, h_ray_length, par, ray_index);
		par->player->dir_angle += step_angle;
		ray_index++;
	}
	par->player->dir_angle = par->current_angle;
}

void	the_3d_projection(t_parameters *par)
{
	int		ray_index;
	double	distance_to_screen_projection;
	double	projected_wall_height;
	double	corrected_distance;

	ray_index = 0;
	distance_to_screen_projection = (par->screen_width / 2)
		/ tan(par->player->fov / 2);
	while (ray_index < par->screen_width)
	{
		corrected_distance = par->rayc->casted_rays[ray_index].distance
			* cos(par->rayc->casted_rays[ray_index].casted_ray_rotation_angle
				- par->player->dir_angle);
		projected_wall_height = par->tilesize * (distance_to_screen_projection
				/ corrected_distance);
		draw_wall(par, ray_index, projected_wall_height);
		ray_index++;
	}
}
