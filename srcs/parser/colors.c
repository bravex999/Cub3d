#include "cub.h"

static int	is_num(char *s)
{
	int	i;
	int	got;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == ' ')
		i++;
	got = 0;
	while (s[i] && ft_isdigit((unsigned char)s[i]))
	{
		got = 1;
		i++;
	}
	while (s[i] == ' ')
		i++;
	return (got && s[i] == '\0');
}

static int	read_rgb_values(char *p, int rgb[3])
{
	char	**v;
	int		i;

	v = ft_split(p, ',');
	if (!v)
		return (-1);
	i = 0;
	while (v[i])
		i++;
	if (i != 3 || !is_num(v[0]) || !is_num(v[1]) || !is_num(v[2]))
	{
		i = 0;
		while (v[i])
			free(v[i++]);
		return (free(v), -1);
	}
	rgb[0] = ft_atoi(v[0]);
	rgb[1] = ft_atoi(v[1]);
	rgb[2] = ft_atoi(v[2]);
	i = 0;
	while (v[i])
		free(v[i++]);
	free(v);
	return (0);
}

static int	range_ok(int rgb[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (-1);
		i++;
	}
	return (0);
}

static int	save_rgb(char id, t_cub_raw *out, int rgb[3])
{
	int	i;

	if (id == 'F')
	{
		if (out->floor_rgb[0] != -1)
			return (-1);
		i = 0;
		while (i < 3)
			out->floor_rgb[i++] = rgb[i - 1];
		return (0);
	}
	if (id == 'C')
	{
		if (out->ceiling_rgb[0] != -1)
			return (-1);
		i = 0;
		while (i < 3)
			out->ceiling_rgb[i++] = rgb[i - 1];
		return (0);
	}
	return (-1);
}

int	hdr_parse_col(char *line, t_cub_raw *out)
{
	char	*p;
	char	id;
	int		rgb[3];

	if (!line || !out)
		return (-1);
	p = line;
	while (*p == ' ')
		p++;
	id = *p;
	if (id != 'F' && id != 'C')
		return (-1);
	p++;
	while (*p == ' ')
		p++;
	if (read_rgb_values(p, rgb) == -1)
		return (-1);
	if (range_ok(rgb) == -1)
		return (-1);
	if (save_rgb(id, out, rgb) == -1)
		return (-1);
	return (0);
}

