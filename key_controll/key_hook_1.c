/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:30:47 by asabir            #+#    #+#             */
/*   Updated: 2025/05/14 16:34:55 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	rotate_player(t_parameters *parameters, int right)
{
	if (right)
	{
		parameters->player->dir_angle = normalize_angle(
				parameters->player->dir_angle
				+ parameters->player->rotation_angle);
		draw_map(parameters);
	}
	else
	{
		parameters->player->dir_angle = normalize_angle(
				parameters->player->dir_angle
				- parameters->player->rotation_angle);
		draw_map(parameters);
	}
}

int	key_controll(t_parameters *parameters)
{
	double	next_x;
	double	next_y;

	next_x = 0;
	next_y = 0;
	reset_mlx_img(parameters);
	if (parameters->click[0] == 1)
		rotate_player(parameters, 0);
	else if (parameters->click[1] == 1)
		rotate_player(parameters, 1);
	else if (parameters->click[2] == 1)
		move_up(parameters, next_x, next_y);
	else if (parameters->click[3] == 1)
		move_down(parameters, next_x, next_y);
	else if (parameters->click[4] == 1)
		move_left(parameters, next_x, next_y);
	else if (parameters->click[5] == 1)
		move_right(parameters, next_x, next_y);
	return (0);
}
