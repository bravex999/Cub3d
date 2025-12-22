/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:11:59 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 16:12:01 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	wall_right(char **m, int w, int i, int j);

static int	is_walkable(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	wall_up(char **m, int h, int i, int j)
{
	int		x;
	char	c;

	(void)h;
	x = i - 1;
	while (x >= 0)
	{
		c = m[x][j];
		if (c == ' ')
			return (0);
		if (c == '1')
			return (1);
		x--;
	}
	return (0);
}

static int	wall_down(char **m, int h, int i, int j)
{
	int		x;
	char	c;

	x = i + 1;
	while (x < h)
	{
		c = m[x][j];
		if (c == ' ')
			return (0);
		if (c == '1')
			return (1);
		x++;
	}
	return (0);
}

static int	wall_left(char **m, int w, int i, int j)
{
	int		y;
	char	c;

	(void)w;
	y = j - 1;
	while (y >= 0)
	{
		c = m[i][y];
		if (c == ' ')
			return (0);
		if (c == '1')
			return (1);
		y--;
	}
	return (0);
}

int	map_is_closed(char **m, int w, int h)
{
	int		i;
	int		j;
	char	c;

	if (!m || w <= 0 || h <= 0)
		return (-1);
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			c = m[i][j];
			if (is_walkable(c))
				if (!wall_up(m, h, i, j) || !wall_down(m, h, i, j)
					|| !wall_left(m, w, i, j) || !wall_right(m, w, i, j))
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
