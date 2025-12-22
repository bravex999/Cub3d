/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init_gfx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:58:12 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 15:58:14 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	app_init_mlx(t_app *app)
{
	if (!app)
		return (-1);
	app->mlx = mlx_init();
	if (!app->mlx)
		return (error_msg("Mlx init failed"));
	app->win = mlx_new_window(app->mlx, WIN_W, WIN_H, "Cub3D");
	if (!app->win)
		return (error_msg("Window creation failed"));
	return (0);
}

static int	app_init_frame(t_app *app)
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	if (!app || !app->mlx)
		return (-1);
	img = mlx_new_image(app->mlx, WIN_W, WIN_H);
	if (!img)
		return (error_msg("Image creation failed"));
	addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
	if (!addr)
		return (error_msg("Data addr failed"));
	app->frame_img = img;
	app->scene.frame.width = WIN_W;
	app->scene.frame.height = WIN_H;
	app->scene.frame.pixels = addr;
	return (0);
}

int	app_init_gfx(t_app *app)
{
	if (!app)
		return (-1);
	if (app_init_mlx(app) == -1)
		return (-1);
	if (app_init_frame(app) == -1)
		return (-1);
	return (0);
}
