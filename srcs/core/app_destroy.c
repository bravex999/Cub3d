/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:57:56 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 15:57:58 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free_map_grid(t_map *map)
{
	int	y;

	if (!map || !map->grid)
		return ;
	y = 0;
	while (y < map->height)
	{
		free(map->grid[y]);
		y++;
	}
	free(map->grid);
	map->grid = NULL;
}

static void	free_tex_paths(t_texture_paths *paths)
{
	if (!paths)
		return ;
	if (paths->no)
	{
		free(paths->no);
		paths->no = NULL;
	}
	if (paths->so)
	{
		free(paths->so);
		paths->so = NULL;
	}
	if (paths->we)
	{
		free(paths->we);
		paths->we = NULL;
	}
	if (paths->ea)
	{
		free(paths->ea);
		paths->ea = NULL;
	}
}

void	app_destroy(t_app *app)
{
	if (!app)
		return ;
	free_map_grid(&app->scene.map);
	free_tex_paths(&app->tex_paths);
}
