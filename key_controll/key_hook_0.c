/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:33:23 by asabir            #+#    #+#             */
/*   Updated: 2025/05/14 16:20:38 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	on_destroy(t_parameters *par)
{
	mlx_destroy_image(par->connection, par->img);
	mlx_destroy_window(par->connection, par->window);
	if (par->we_texture)
		mlx_destroy_image(par->connection, par->we_texture);
	if (par->no_texture)
		mlx_destroy_image(par->connection, par->no_texture);
	if (par->ea_texture)
		mlx_destroy_image(par->connection, par->ea_texture);
	if (par->so_texture)
		mlx_destroy_image(par->connection, par->so_texture);
	free_param(par->pars);
	mlx_destroy_display(par->connection);
	free(par->connection);
	free(par->player);
	free(par->rayc);
	free(par);
	exit(0);
}

// 1- angle rotation left
// 2- angle rotation right
// 3- up
// 4-down
// 3- left
// 4-right
int	press(int button, t_parameters *parameters)
{
	if (button == 65361)
		parameters->click[0] = 1;
	else if (button == 65363)
		parameters->click[1] = 1;
	else if (button == 119)
		parameters->click[2] = 1;
	else if (button == 115)
		parameters->click[3] = 1;
	else if (button == 97)
		parameters->click[4] = 1;
	else if (button == 100)
		parameters->click[5] = 1;
	else if (button == 65307)
		on_destroy(parameters);
	return (0);
}

int	release(int button, t_parameters *parameters)
{
	if (button == 65361)
		parameters->click[0] = 0;
	else if (button == 65363)
		parameters->click[1] = 0;
	else if (button == 119)
		parameters->click[2] = 0;
	else if (button == 115)
		parameters->click[3] = 0;
	else if (button == 97)
		parameters->click[4] = 0;
	else if (button == 100)
		parameters->click[5] = 0;
	else if (button == 65307)
		on_destroy(parameters);
	return (0);
}
