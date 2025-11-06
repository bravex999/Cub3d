#include "cub.h"

int	line_is_blank(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	h_or_s(const char *line, t_headers *h, t_map_buf *map, int *to_map)
{
	int	result;

	*to_map = 0;
	if (is_header_line(line))
	{
		result = headers_accept_line(line, h);
		if (result < 0)
			return (-1);
		return (0);
	}
	if (is_map_line(line))
	{
		if (!headers_complete(h))
			return (-1);
		if (map_push(map, line) < 0)
			return (-1);
		*to_map = 1;
		return (0);
	}
	return (-1);
}

int	map_or_post(const char *line, t_map_buffer *map, int *to_post)
{
	*to_post = 0;
	if (is_map_line(line))
	{
		if (map_push(map, line) < 0)
			return (-1);
		return (0);
	}
	if (line_is_blank(line))
	{
		*to_post = 1;
		return (0);
	}
	return (-1);
}

