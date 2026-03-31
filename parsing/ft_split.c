/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shassoun <shassoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:42:45 by shassoun          #+#    #+#             */
/*   Updated: 2025/05/03 14:42:46 by shassoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_words(char const *s, char c)
{
	int	flag;
	int	i;
	int	a;

	flag = 0;
	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] != c && flag != 1)
		{
			a++;
			flag = 1;
		}
		if (s[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	return (a);
}

static int	free_result(char **result, int j)
{
	while (j > 0)
	{
		free(result[j - 1]);
		j--;
	}
	free(result);
	return (1);
}

static void	strncp_yy(char *dest, char const *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[n] = '\0';
}

static int	tl(char **result, char const *s, char c, int *j)
{
	int	i;
	int	ts;
	int	te;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			ts = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			te = i - 1;
			result[*j] = (char *)malloc(te - ts + 2);
			if (!result[*j])
			{
				return (free_result(result, *j));
			}
			strncp_yy(result[*j], s + ts, te - ts + 1);
			(*j)++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	char	**result;

	j = 0;
	result = NULL;
	if (s == NULL)
		return (result);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (s[0] == '\0')
	{
		result[0] = NULL;
		return (result);
	}
	i = tl(result, s, c, &j);
	if (i == 1)
		return (NULL);
	result[count_words(s, c)] = NULL;
	return (result);
}
