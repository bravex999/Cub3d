#include "cub.h"

static char	*dup_line_raw(const char *str)
{
	int		len;
	int		i;
	char	*copy;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	copy = (char *)malloc((unsigned int)len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int	map_grow_to(t_map_buf *map, int new_cap)
{
	char	**nv;
	int		i;

	nv = (char **)malloc(sizeof(char *) * (unsigned int)new_cap);
	if (!nv)
		return (-1);
	i = 0;
	while (i < map->count)
	{
		nv[i] = map->lines[i];
		i++;
	}
	free(map->lines);
	map->lines = nv;
	map->cap = new_cap;
	return (0);
}

void	map_init(t_map_buf *map)
{
	map->lines = NULL;
	map->count = 0;
	map->cap = 0;
}

int	map_push(t_map_buf *map, const char *str)
{
	char	*line;

	if (map->count == map->cap)
	{
		if (map->cap == 0 && map_grow_to(map, 16) < 0)
			return (-1);
		if (map->cap > 0 && map->count == map->cap)
		{
			if (map_grow_to(map, map->cap * 2) < 0)
				return (-1);
		}
	}
	line = dup_line_raw(str);
	if (!line)
		return (-1);
	map->lines[map->count] = line;
	map->count += 1;
	return (0);
}

void	map_free(t_map_buf *map)
{
	int	i;

	i = 0;
	while (i < map->count)
	{
		if (map->lines[i])
			free(map->lines[i]);
		i++;
	}
	free(map->lines);
	map->lines = NULL;
	map->count = 0;
	map->cap = 0;
}
