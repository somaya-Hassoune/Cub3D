/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:44:20 by shassoun          #+#    #+#             */
/*   Updated: 2025/05/06 14:15:06 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	print_textures_error_and_free(t_parameters *par)
{
	ft_putstr_fd("Error: Failed to load texture\n", 2);
	on_destroy(par);
}

void	load_textures(t_parameters *par, t_map *params)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	par->no_texture = NULL;
	par->so_texture = NULL;
	par->ea_texture = NULL;
	par->we_texture = NULL;
	par->no_texture = mlx_xpm_file_to_image(par->connection,
			params->textures[0], &a, &b);
	if (!par->no_texture)
		print_textures_error_and_free(par);
	par->so_texture = mlx_xpm_file_to_image(par->connection,
			params->textures[1], &a, &b);
	if (!par->so_texture)
		print_textures_error_and_free(par);
	par->we_texture = mlx_xpm_file_to_image(par->connection,
			params->textures[2], &a, &b);
	if (!par->we_texture)
		print_textures_error_and_free(par);
	par->ea_texture = mlx_xpm_file_to_image(par->connection,
			params->textures[3], &a, &b);
	if (!par->ea_texture)
		print_textures_error_and_free(par);
}

int	is_big_map(t_map *param)
{
	int	i;
	int	j;

	j = 0;
	while (param->map_only[j])
	{
		i = 0;
		while (param->map_only[j][i])
		{
			i++;
		}
		if (i > 40)
			return (1);
		j++;
		if (j > 30)
			return (1);
	}
	return (0);
}

int	*full_arg(int *arg, int a, int b, int c)
{
	arg[0] = a;
	arg[1] = b;
	arg[2] = c;
	return (arg);
}

int	is_that_2d(int x, int y, t_parameters *par)
{
	int	map_x;
	int	map_y;

	map_x = x / (par->tilesize * par->minimap_factor);
	map_y = y / (par->tilesize * par->minimap_factor);
	if (map_y < 0 || map_y >= par->map_height)
		return (0);
	if (map_x < 0 || map_x >= par->map_width_rows[map_y])
		return (0);
	return (1);
}
