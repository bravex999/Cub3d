/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:11:27 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 16:11:31 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	is_spawn(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	map_check_charset(char **blk)
{
	int		i;
	int		j;
	char	c;

	if (!blk)
		return (-1);
	i = 0;
	while (blk[i])
	{
		j = 0;
		while (blk[i][j])
		{
			c = blk[i][j];
			if (c != '0' && c != '1' && !is_spawn(c) && c != ' ')
				return (error_msg("invalid chars found in map"));
			j++;
		}
		i++;
	}
	return (0);
}
