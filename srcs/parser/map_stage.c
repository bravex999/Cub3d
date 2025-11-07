#include "cub.h"

static int	block_size(char **blk, int *w, int *h)
{
	int	i;
	int	cur;

	*w = 0;
	*h = 0;
	i = 0;
	while (blk[i])
	{
		cur = (int)ft_strlen(blk[i]);
		if (cur > *w)
			*w = cur;
		(*h)++;
		i++;
	}
	if (*w <= 0 || *h <= 0)
		return (-1);
	return (0);
}

int	map_stage(char **lines, int map_start, t_cub_raw *out)
{
	char	**blk;
	int		w;
	int		h;
	int		pos[2];
	char	dir;

	if (!lines || !out || map_start < 0)
		return (-1);
	blk = &lines[map_start];
	if (map_check_charset(blk) == -1)
		return (-1);
	if (map_scan_spawn(blk, pos, &dir) == -1)
		return (-1);
	out->spawn_x = pos[0];
	out->spawn_y = pos[1];
	out->spawn_dir = dir;
	if (block_size(blk, &w, &h) == -1)
		return (-1);
	if (map_alloc_rect(out, w, h) == -1)
		return (-1);
	if (map_copy_rect(blk, out->map, w, h) == -1)
		return (-1);
	if (map_is_closed(out->map, w, h) == -1)
		return (-1);
	return (0);
}
