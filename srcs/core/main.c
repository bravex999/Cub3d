#include "cub.h"

static int	color_to_int(t_color c)
{
	return ((c.r << 16) | (c.g << 8) | c.b);
}

int	main(int argc, char **argv)
{
	t_cub_raw	raw;
	t_app		app;
	int			ceiling_c;
	int			floor_c;

	if (argc != 2)
		return (error_msg("Usage: ./cub3d <map.cub>"));
	if (parse_cub(argv[1], &raw) == -1)
		return (1);
	if (app_init_from_raw(&app, &raw) == -1)
		return (1);
	if (app_init_gfx(&app) == -1)
		return (1);
	if (app_load_textures(&app) == -1)
		return (1);
	ceiling_c = color_to_int(app.scene.ceiling);
	floor_c = color_to_int(app.scene.floor);
	frame_clear(&app.scene.frame, ceiling_c, floor_c);
	mlx_put_image_to_window(app.mlx, app.win, app.frame_img, 0, 0);
	mlx_loop(app.mlx);
	return (0);
}

