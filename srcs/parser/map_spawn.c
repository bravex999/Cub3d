#include "cub.h"

static int	count_spawn_line(char *s, int row, int pos[2], char *dir)
{
	int		j;
	int		n;
	char	c;

	j = 0;
	n = 0;
	while (s[j])
	{
		c = s[j];
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			n++;
			if (pos)
			{
				pos[0] = j;
				pos[1] = row;
			}
			if (dir)
				*dir = c;
		}
		j++;
	}
	return (n);
}

int	map_scan_spawn(char **blk, int pos[2], char *dir)
{
	int	i;
	int	total;

	if (!blk)
		return (-1);
	i = 0;
	total = 0;
	while (blk[i])
	{
		total += count_spawn_line(blk[i], i, pos, dir);
		if (total > 1)
			return (error_msg("more than one player found"));
		i++;
	}
	if (total == 1)
		return (0);
	return (error_msg("no player found"));
}
