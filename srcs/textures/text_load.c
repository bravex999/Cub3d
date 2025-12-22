/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:22:07 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 16:22:09 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	tex_set_data(t_texture *tex, void *img)
{
	int	bpp;
	int	line_len;
	int	endian;

	tex->pixels = mlx_get_data_addr(img, &bpp, &line_len, &endian);
	if (!tex->pixels)
		return (error_msg("Texture data failed"));
	tex->bpp = bpp;
	tex->line_len = line_len;
	tex->endian = endian;
	return (0);
}

static int	tex_load_one(t_app *app, t_tex_id id, const char *path)
{
	t_texture	*tex;
	void		*img;
	int			w;
	int			h;

	if (!app || !app->mlx || !path)
		return (error_msg("Texture path invalid"));
	img = mlx_xpm_file_to_image(app->mlx, (char *)path, &w, &h);
	if (!img)
		return (error_msg("Texture load failed"));
	tex = &app->scene.textures[id];
	tex->img = img;
	tex->width = w;
	tex->height = h;
	if (tex_set_data(tex, img) == -1)
		return (-1);
	return (0);
}

int	app_load_textures(t_app *app)
{
	if (!app)
		return (-1);
	if (tex_load_one(app, TEX_NO, app->tex_paths.no) == -1)
		return (-1);
	if (tex_load_one(app, TEX_SO, app->tex_paths.so) == -1)
		return (-1);
	if (tex_load_one(app, TEX_WE, app->tex_paths.we) == -1)
		return (-1);
	if (tex_load_one(app, TEX_EA, app->tex_paths.ea) == -1)
		return (-1);
	return (0);
}
