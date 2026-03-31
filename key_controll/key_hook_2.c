/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:23:14 by asabir            #+#    #+#             */
/*   Updated: 2025/05/18 21:50:20 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	move_left(t_parameters *parameters, double next_x, double next_y)
{
	next_x = parameters->player->x + cos(parameters->player->dir_angle
			- M_PII / 2) * parameters->player->walk_speed;
	next_y = parameters->player->y + sin(parameters->player->dir_angle
			- M_PII / 2) * parameters->player->walk_speed;
	if (check_if_there_is_a_wall(parameters, next_x, next_y) != 1)
	{
		parameters->player->x = next_x;
		parameters->player->y = next_y;
		draw_map(parameters);
	}
}

void	move_right(t_parameters *parameters, double next_x, double next_y)
{
	next_x = parameters->player->x + cos(parameters->player->dir_angle
			+ M_PII / 2) * parameters->player->walk_speed;
	next_y = parameters->player->y + sin(parameters->player->dir_angle
			+ M_PII / 2) * parameters->player->walk_speed;
	if (check_if_there_is_a_wall(parameters, next_x, next_y) != 1)
	{
		parameters->player->x = next_x;
		parameters->player->y = next_y;
		draw_map(parameters);
	}
}

void	move_up(t_parameters *parameters, double next_x, double next_y)
{
	next_x = parameters->player->x + cos(parameters->player->dir_angle)
		* parameters->player->walk_speed;
	next_y = parameters->player->y + sin(parameters->player->dir_angle)
		* parameters->player->walk_speed;
	if (check_if_there_is_a_wall(parameters, next_x, next_y) != 1)
	{
		parameters->player->x = next_x;
		parameters->player->y = next_y;
		draw_map(parameters);
	}
}

void	move_down(t_parameters *parameters, double next_x, double next_y)
{
	next_x = parameters->player->x - cos(parameters->player->dir_angle)
		* parameters->player->walk_speed;
	next_y = parameters->player->y - sin(parameters->player->dir_angle)
		* parameters->player->walk_speed;
	if (check_if_there_is_a_wall(parameters, next_x, next_y) != 1)
	{
		parameters->player->x = next_x;
		parameters->player->y = next_y;
		draw_map(parameters);
	}
}

void	reset_mlx_img(t_parameters *parameters)
{
	if (parameters->img)
		mlx_destroy_image(parameters->connection, parameters->img);
	parameters->img = mlx_new_image(parameters->connection,
			parameters->screen_width, parameters->screen_height);
	parameters->address = mlx_get_data_addr(parameters->img,
			&(parameters->bits_per_pixel), &parameters->size_line,
			&parameters->endian);
}
