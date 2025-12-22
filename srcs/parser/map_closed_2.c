/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:11:46 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 16:11:48 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* srcs/parser/map_closed_right.c */
#include "cub.h"

int	wall_right(char **m, int w, int i, int j)
{
	int		y;
	char	c;

	y = j + 1;
	while (y < w)
	{
		c = m[i][y];
		if (c == ' ')
			return (0);
		if (c == '1')
			return (1);
		y++;
	}
	return (0);
}
