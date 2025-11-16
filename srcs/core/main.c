#include "cub.h"

int	main(int argc, char **argv)
{
	t_cub_raw	raw;
	int			ret;

	if (argc != 2)
	{
		printf("Usage: %s map.cub\n", argv[0]);
		return (1);
	}
	ret = parse_cub(argv[1], &raw);
	if (ret != 0)
		return (1);
	printf("OK: %s\n", argv[1]);
	printf("map %dx%d, spawn=(%d,%d,%c)\n",
		raw.map_w, raw.map_h, raw.spawn_x, raw.spawn_y, raw.spawn_dir);
	/* free_cub_raw(&raw);  // cuando la implementes */
	return (0);
}

