/* srcs/parser/map_closed_right.c */
#include "cub.h"

int	wall_right(char **m, int w, int i, int j)
{
	int		y;
	char	c;

	y = j + 1;
	while (y < w)
	{
		c = m[i][y];
		if (c == ' ')
			return (0);
		if (c == '1')
			return (1);
		y++;
	}
	return (0);
}
