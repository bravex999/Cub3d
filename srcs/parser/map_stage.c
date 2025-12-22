/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_stage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:12:23 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 16:12:25 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	line_not_blank(char *s)
{
	int	j;

	j = 0;
	while (s[j])
	{
		if (s[j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

static int	block_size(char **blk, int *w, int *h)
{
	int	i;
	int	cur;
	int	last;

	*w = 0;
	*h = 0;
	last = -1;
	i = 0;
	while (blk[i])
	{
		if (line_not_blank(blk[i]))
		{
			last = i;
			cur = (int)ft_strlen(blk[i]);
			if (cur > *w)
				*w = cur;
		}
		i++;
	}
	if (last < 0 || *w <= 0)
		return (-1);
	*h = last + 1;
	return (0);
}

int	map_stage(char **lines, int map_start, t_cub_raw *out)
{
	char	**blk;
	int		w;
	int		h;
	int		pos[2];
	char	dir;

	if (!lines || !out || map_start < 0)
		return (-1);
	blk = &lines[map_start];
	if (map_check_charset(blk) == -1)
		return (-1);
	if (map_scan_spawn(blk, pos, &dir) == -1)
		return (-1);
	out->spawn_x = pos[0];
	out->spawn_y = pos[1];
	out->spawn_dir = dir;
	if (block_size(blk, &w, &h) == -1)
		return (error_msg("Empty map"));
	if (map_alloc_rect(out, w, h) == -1)
		return (-1);
	if (map_copy_rect(blk, out->map, w, h) == -1)
		return (-1);
	if (map_is_closed(out->map, w, h) == -1)
		return (error_msg("Map not closed or with invalid spaces"));
	return (0);
}
