#include "cub.h"

static int	step_line(const char *line, t_headers *h,
		t_map_buf *map, t_parse_stage *stage)
{
	int	to_map;
	int	to_post;

	if (*stage == ST_HEADERS)
	{
		if (line_is_blank(line))
			return (0);
		if (h_or_s(line, h, (t_map_buf *)map, &to_map) < 0)
			return (-1);
		if (to_map)
			*stage = ST_MAP;
		return (0);
	}
	if (*stage == ST_MAP)
	{
		if (map_or_post(line, map, &to_post) < 0)
			return (-1);
		if (to_post)
			*stage = ST_POST;
		return (0);
	}
	if (!line_is_blank(line))
		return (-1);
	return (0);
}

static int	read_loop(int fd, t_headers *h, t_map_buf *map)
{
	char			*line;
	t_parse_stage	stage;
	int				error;

	stage = ST_HEADERS;
	error = 0;
	line = get_next_line(fd);
	while (line != NULL && !error)
	{
		if (step_line(line, h, map, &stage) < 0)
			error = 1;
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		free(line);
	if (error)
		return (-1);
	if (!headers_complete(h) || map->count == 0)
		return (-1);
	return (0);
}

static int	finish_ok(t_cub_raw *out, t_headers *h, t_map_buf *map)
{
	if (cub_raw_set_headers(out, h) < 0)
	{
		headers_free(h);
		map_free(map);
		return (-1);
	}
	headers_free(h);
	if (cub_raw_take_map(out, map) < 0)
	{
		map_free(map);
		return (-1);
	}
	return (0);
}

int	parse_cub(const char *filename, t_cub_raw *out)
{
	int				fd;
	int				r;
	t_headers		h;
	t_map_buf		map;

	cub_raw_init(out);
	headers_init(&h);
	map_init(&map);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	r = read_loop(fd, &h, &map);
	close(fd);
	if (r < 0)
	{
		headers_free(&h);
		map_free(&map);
		return (-1);
	}
	if (finish_ok(out, &h, &map) < 0)
		return (-1);
	return (0);
}
