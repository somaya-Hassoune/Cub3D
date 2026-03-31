/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 22:28:22 by asabir            #+#    #+#             */
/*   Updated: 2025/05/06 22:29:29 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	scale1(int a, int b, int x, int map_size)
{
	return ((b - a) * x / map_size + a);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		write(fd, &str[i++], 1);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	dest = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	my_mlx_pixel_put(t_parameters *par, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= par->screen_width || y >= par->screen_height)
		return ;
	dst = par->address + (y * par->size_line) + (x * (par->bits_per_pixel / 8));
	*(int *)dst = color;
}

double	normalize_angle(double angle)
{
	angle = fmod(angle, 2 * M_PII);
	if (angle < 0)
	{
		angle = 2 * M_PII + angle;
	}
	return (angle);
}
