/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:07:38 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 16:07:40 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	scene_init_dir(t_player *pl, char dir);

static void	scene_init_map(t_scene *scene, const t_cub_raw *raw)
{
	scene->map.grid = raw->map;
	scene->map.width = raw->map_w;
	scene->map.height = raw->map_h;
	scene->map.spawn_x = raw->spawn_x;
	scene->map.spawn_y = raw->spawn_y;
	scene->map.spawn_dir = raw->spawn_dir;
}

static void	scene_init_player(t_scene *scene, const t_cub_raw *raw)
{
	scene->player.pos.x = (double)raw->spawn_x + 0.5;
	scene->player.pos.y = (double)raw->spawn_y + 0.5;
	scene_init_dir(&scene->player, raw->spawn_dir);
}

static void	scene_init_colors(t_scene *scene, const t_cub_raw *raw)
{
	scene->floor.r = raw->floor_rgb[0];
	scene->floor.g = raw->floor_rgb[1];
	scene->floor.b = raw->floor_rgb[2];
	scene->ceiling.r = raw->ceiling_rgb[0];
	scene->ceiling.g = raw->ceiling_rgb[1];
	scene->ceiling.b = raw->ceiling_rgb[2];
}

static void	scene_init_tex_frame(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		scene->textures[i].width = 0;
		scene->textures[i].height = 0;
		scene->textures[i].pixels = NULL;
		i++;
	}
	scene->frame.width = 0;
	scene->frame.height = 0;
	scene->frame.pixels = NULL;
}

int	scene_init_from_raw(t_scene *scene, const t_cub_raw *raw)
{
	if (!scene || !raw)
		return (-1);
	scene_init_map(scene, raw);
	scene_init_player(scene, raw);
	scene_init_colors(scene, raw);
	scene_init_tex_frame(scene);
	return (0);
}
