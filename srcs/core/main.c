#include "cub.h"

int	main(int argc, char **argv)
{
	t_cub_raw	raw;
	t_app		app;

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
	render_frame(&app);
	mlx_loop(app.mlx);
	return (0);
}

