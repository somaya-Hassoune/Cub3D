/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:14:49 by shassoun          #+#    #+#             */
/*   Updated: 2025/05/07 14:36:16 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define C 5
# define F 6

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
	char	**map_only;
	char	textures[5][4096];
	char	direction;
	int		c_color[3];
	int		f_color[3];
	int		player[2];
	int		*map_width_rows;
	int		map_height;
}			t_map;

size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str, t_map *param);
char		**get_map(char *file, t_map *par);
char		*get_next_line(int fd);
char		*ft_strjoin(char **line, char *buff);
char		**ft_split(char const *s, char c);
void		free_param(t_map *param);
void		_write(int fd, char *str, int line, t_map *param);
int			check_all_para_are_loaded(int *tab);
void		get_num(char num[4], char *line, int *i, t_map *param);
void		get_numbers_rgb(char *line, int i, t_map *param, int val);
void		check_player(char *line, t_map *param, int j, int *flag);
int			whach_ghi_lvalid_chars(char **map, t_map *param);
int			closed_map_suit(char **map, int i, int j, t_map *param);
int			whach_lmap_msdoda(char **map, t_map *param);
void		pars_map(char **map, int j, t_map *param);
int			check_the_2chars(char *str, int i);
int			check_the_colors(char *str, int i);
int			check_xpm(char *str);
void		direction(char *line, int *tab, t_map *param, int *i);
void		color(char *line, int *tab, t_map *param, int *i);
void		initialize_tab(int *tab);
void		pars_the_map(char **map, t_map *param);
t_map		*parsing(int argc, char **argv);
void		ft_putstr_fd(char *str, int fd);

#endif