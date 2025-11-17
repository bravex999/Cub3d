#include "cub.h"

int	main(int argc, char **argv)
{
	t_cub_raw	raw;
	t_scene		scene;

	if (argc != 2)
	{
		error_msg("Usage: ./cub3d <map.cub>");
		return (1);
	}
	if (parse_cub(argv[1], &raw) == -1)
		return (1);
	if (scene_init_from_raw(&scene, &raw) == -1)
		return (1);
	printf("map %dx%d, spawn=(%d,%d,%c)\n",
		scene.map.width, scene.map.height,
		scene.map.spawn_x, scene.map.spawn_y,
		scene.map.spawn_dir);
	return (0);
}

