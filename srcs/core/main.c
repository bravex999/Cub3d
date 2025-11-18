#include "cub.h"

static int	print_usage(void)
{
	return (error_msg("Usage: ./cub3d <map.cub>"));
}

int	main(int argc, char **argv)
{
	t_cub_raw	raw;
	t_app		app;

	if (argc != 2)
		return (print_usage());
	if (parse_cub(argv[1], &raw) == -1)
		return (free_error(&raw, NULL));
	if (app_init_from_raw(&app, &raw) == -1)
		return (free_error(&raw, &app));
	if (app_init_gfx(&app) == -1)
		return (free_error(&raw, &app));
	if (app_load_textures(&app) == -1)
		return (free_error(&raw, &app));
	render_frame(&app);
	mlx_hook(app.win, 2, 1L << 0, app_key_press, &app);
	mlx_hook(app.win, 3, 1L << 1, app_key_release, &app);
	mlx_hook(app.win, 17, 0, app_close_window, &app);
	mlx_loop_hook(app.mlx, app_update, &app);
	mlx_loop(app.mlx);
	app_destroy(&app);
	free_error(&raw, NULL);
	return (0);
}

