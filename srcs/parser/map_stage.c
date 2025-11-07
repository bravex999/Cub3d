#include "cub.h"

int	map_stage(char **lines, int map_start, t_cub_raw *out)
{
	char	**blk;
	int		w;
	int		h;

	if (!lines || !out || map_start < 0)
		return (-1);
	blk = &lines[map_start];
	if (check_charset(blk) == -1)
		return (-1);
	if (find_spawn(blk, out) == -1)
		return (-1);
	if (count_size(blk, &w, &h) == -1)
		return (-1);
	if (alloc_grid(out, w, h) == -1)
		return (-1);
	if (copy_rect(blk, out->map, w, h) == -1)
		return (-1);
	if (is_closed(out->map, w, h) == -1)
		return (-1);
	return (0);
}
