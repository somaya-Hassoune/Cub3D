/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 23:59:43 by asabir            #+#    #+#             */
/*   Updated: 2025/05/14 16:33:11 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# define ON_DESTROY 17
# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define M_PII 3.14159265358979323846

typedef struct Palayer
{
	double			x;
	double			y;
	double			dir_angle;
	int				walk_speed;
	double			rotation_angle;
	int				radius;
	int				facing_up;
	int				facing_right;
	double			fov;
}					t_player;

typedef struct casted_rays
{
	double			distance;
	double			x_hit;
	double			y_hit;
	double			casted_ray_rotation_angle;
	int				is_vertical;

}					t_casted_rays;

typedef struct Ray
{
	double			v_x_intersec;
	double			v_y_intersec;
	double			h_x_intersec;
	double			h_y_intersec;
	t_casted_rays	casted_rays[1920];
}					t_raycasting;

typedef struct s_map
{
	char			**map;
	char			**map_only;
	char			textures[5][4096];
	char			direction;
	int				c_color[3];
	int				f_color[3];
	int				player[2];
	int				*map_width_rows;
	int				map_height;

}					t_map;

typedef struct s_texture
{
	void			*texture;
	int				width;
	int				height;
}					t_texture;
typedef struct Parameters
{
	void			*image;
	void			*connection;
	void			*img;
	char			*address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	void			*window;
	char			**map;
	int				map_width;
	int				*map_width_rows;
	int				map_height;
	double			tilesize;
	t_player		*player;
	t_raycasting	*rayc;
	t_map			*pars;
	int				screen_width;
	int				screen_height;
	double			minimap_factor;
	void			*no_texture;
	void			*so_texture;
	void			*we_texture;
	void			*ea_texture;
	int				c_clr[3];
	int				f_clr[3];
	int				click[6];
	double			current_angle;
}					t_parameters;

t_map				*parsing(int argc, char **argv);
void				_write(int fd, char *str, int line, t_map *param);
void				my_mlx_pixel_put(t_parameters *par, int i, int j,
						int color);
double				scale1(int a, int b, int x, int map_size);
void				draw_map(t_parameters *parameters);
void				ft_putstr_fd(char *str, int fd);
char				*ft_strdup(char *str);
int					load_map(t_parameters *parameters);
int					ft_strlen(char *str);
int					parse_map(t_parameters *parameters);
void				draw_circle(t_parameters *parameters);
int					check_if_there_is_a_wall(t_parameters *parameters, double x,
						double y);
void				draw_line(t_parameters *parameters, char check);
void				reflect_ray(t_parameters *par);
double				normalize_angle(double angle);
void				draw_wall(t_parameters *par, int x, int wall_height);
void				the_3d_projection(t_parameters *par);
int					key_controll(t_parameters *parameters);
void				set_direction_informations(t_parameters *par);
int					key_down(int button, t_parameters *parameters);
int					on_destroy(t_parameters *par);
int					release(int button, t_parameters *parameters);
int					press(int button, t_parameters *parameters);
int					is_big_map(t_map *param);
int					get_texture_color(void *texture, int x, int y);
void				coloring_ciel(int start, int end, int x, t_parameters *par);
void				coloring_floor(int start, int end, int x,
						t_parameters *par);
void				coloring_wall(int arg[3], t_parameters *par, void *texture,
						int wall_height);
void				draw_wall(t_parameters *par, int x, int wall_height);
void				load_textures(t_parameters *par, t_map *params);
int					is_big_map(t_map *param);
void				put_map(t_parameters *par);
int					*full_arg(int *arg, int a, int b, int c);
int					is_that_2d(int x, int y, t_parameters *par);
unsigned int		rgb_to_hex(int r, int g, int b);
void				initialisation_para(t_parameters *parameters, t_map *pars);
void				get_map_information(t_parameters *parameters);
void				free_param(t_map *param);
double				vertical_intersections(t_parameters *par);
double				horizontal_intersections(t_parameters *par);
void				move_left(t_parameters *parameters,
						double next_x, double next_y);
void				move_right(t_parameters *parameters,
						double next_x, double next_y);
void				move_up(t_parameters *parameters,
						double next_x, double next_y);
void				move_down(t_parameters *parameters,
						double next_x, double next_y);
void				reset_mlx_img(t_parameters *parameters);
#endif