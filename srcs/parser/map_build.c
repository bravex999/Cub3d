#include "cub.h"

static char	*map_row_new(int w)
{
	int		j;
	char	*r;

	r = (char *)malloc(w + 1);
	if (!r)
		return (NULL);
	j = 0;
	while (j < w)
	{
		r[j] = ' ';
		j++;
	}
	r[w] = '\0';
	return (r);
}

static void	map_free_rows(char **m, int rows)
{
	while (rows-- > 0)
		free(m[rows]);
	free(m);
}

static void	map_set_size(t_cub_raw *out, int w, int h)
{
	out->map_w = w;
	out->map_h = h;
}

int	map_alloc_rect(t_cub_raw *out, int w, int h)
{
	int	i;

	if (!out || w <= 0 || h <= 0)
		return (-1);
	out->map = (char **)malloc(sizeof(char *) * (h + 1));
	if (!out->map)
		return (-1);
	i = 0;
	while (i < h)
	{
		out->map[i] = map_row_new(w);
		if (!out->map[i])
		{
			map_free_rows(out->map, i);
			out->map = NULL;
			return (-1);
		}
		i++;
	}
	out->map[h] = NULL;
	map_set_size(out, w, h);
	return (0);
}

int	map_copy_rect(char **src, char **dst, int w, int h)
{
	int	i;
	int	j;

	if (!src || !dst)
		return (-1);
	i = 0;
	while (i < h && src[i])
	{
		j = 0;
		while (j < w && src[i][j])
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
	return (0);
}
