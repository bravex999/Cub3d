/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:10:52 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 16:10:55 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_cub_raw(t_cub_raw *out)
{
	int	i;

	out->tex_no = NULL;
	out->tex_so = NULL;
	out->tex_we = NULL;
	out->tex_ea = NULL;
	out->map = NULL;
	out->map_w = 0;
	out->map_h = 0;
	out->spawn_x = -1;
	out->spawn_y = -1;
	out->spawn_dir = '\0';
	i = 0;
	while (i < 3)
	{
		out->floor_rgb[i] = -1;
		out->ceiling_rgb[i] = -1;
		i++;
	}
}
