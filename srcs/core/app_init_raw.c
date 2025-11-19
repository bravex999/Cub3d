#include "cub.h"

static void	app_init_tex_paths(t_texture_paths *dst, const t_cub_raw *raw)
{
	if (!dst || !raw)
		return ;
	dst->no = raw->tex_no;
	dst->so = raw->tex_so;
	dst->we = raw->tex_we;
	dst->ea = raw->tex_ea;
}

int	app_init_from_raw(t_app *app, const t_cub_raw *raw)
{
	if (!app || !raw)
		return (-1);
	if (scene_init_from_raw(&app->scene, raw) == -1)
		return (-1);
	app_init_tex_paths(&app->tex_paths, raw);
	return (0);
}
