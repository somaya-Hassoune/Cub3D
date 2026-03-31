/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:28:03 by asabir            #+#    #+#             */
/*   Updated: 2025/05/16 17:19:00 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	manage_starting_position(t_parameters *parametres, t_map *pars)
{
	parametres->player->x = (pars->player[0] * parametres->tilesize)
		+ (parametres->tilesize / 2);
	parametres->player->y = (pars->player[1] * parametres->tilesize)
		+ (parametres->tilesize / 2);
	if (pars->direction == 'N')
		parametres->player->dir_angle = 3 * M_PII / 2;
	else if (pars->direction == 'S')
		parametres->player->dir_angle = M_PII / 2;
	else if (pars->direction == 'E')
		parametres->player->dir_angle = 0;
	else if (pars->direction == 'W')
		parametres->player->dir_angle = M_PII;
}

void	mlx_set_up(t_parameters *parameters)
{
	parameters->connection = mlx_init();
	mlx_get_screen_size(parameters->connection, &(parameters->screen_width),
		&(parameters->screen_height));
	parameters->minimap_factor = sqrt((0.05 * parameters->screen_height
				* parameters->screen_width) / (parameters->map_height
				* parameters->map_width * pow(parameters->tilesize, 2)));
	parameters->window = mlx_new_window(parameters->connection,
			parameters->screen_width, parameters->screen_height, "cub3d");
	parameters->img = mlx_new_image(parameters->connection,
			parameters->screen_width, parameters->screen_height);
	parameters->address = mlx_get_data_addr(parameters->img,
			&(parameters->bits_per_pixel), &parameters->size_line,
			&parameters->endian);
}

void	initialisation_para(t_parameters *parameters, t_map *pars)
{
	parameters->c_clr[0] = pars->c_color[0];
	parameters->c_clr[1] = pars->c_color[1];
	parameters->c_clr[2] = pars->c_color[2];
	parameters->f_clr[0] = pars->f_color[0];
	parameters->f_clr[1] = pars->f_color[1];
	parameters->f_clr[2] = pars->f_color[2];
	parameters->map_height = pars->map_height;
	parameters->map_width_rows = pars->map_width_rows;
	parameters->player->walk_speed = 5;
	parameters->player->fov = M_PII / 3;
	parameters->tilesize = 64;
	parameters->player->rotation_angle = 0.1;
	parameters->click[0] = 0;
	parameters->click[1] = 0;
	parameters->click[2] = 0;
	parameters->click[3] = 0;
	parameters->click[4] = 0;
	parameters->click[5] = 0;
}

int	main(int argc, char **argv)
{
	t_parameters	*parameters;
	t_player		*player;
	t_raycasting	*rayc;
	t_map			*pars;

	pars = parsing(argc, argv);
	parameters = malloc(sizeof(t_parameters));
	parameters->pars = pars;
	player = malloc(sizeof(t_player) * 2);
	rayc = malloc(sizeof(t_raycasting) * 2);
	parameters->rayc = rayc;
	parameters->player = player;
	initialisation_para(parameters, pars);
	parameters->map = pars->map_only;
	manage_starting_position(parameters, pars);
	get_map_information(parameters);
	mlx_set_up(parameters);
	load_textures(parameters, pars);
	draw_map(parameters);
	mlx_hook(parameters->window, ON_KEYDOWN, (1L << 0), press, parameters);
	mlx_hook(parameters->window, ON_KEYUP, (1L << 1), release, parameters);
	mlx_hook(parameters->window, ON_DESTROY, 0, on_destroy, parameters);
	mlx_loop_hook(parameters->connection, key_controll, parameters);
	mlx_loop(parameters->connection);
}
