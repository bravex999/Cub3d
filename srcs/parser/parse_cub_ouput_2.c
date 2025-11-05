#include "cub.h"

int	cub_raw_take_map(t_cub_raw *out, t_map_buffer *map)
{
	out->map = *map;
	out->map_h = out->map.count;
	map->lines = NULL;
	map->count = 0;
	map->cap = 0;
	return (0);
}

void	free_cub_raw(t_cub_raw *cr)
{
	free_paths(cr);
	map_free(&cr->map);
	cr->map_h = 0;
}
