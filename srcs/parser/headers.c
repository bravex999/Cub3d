#include "cub.h"

int		hdr_parse_tex(char *line, t_cub_raw *out);
int		hdr_parse_col(char *line, t_cub_raw *out);

static int	text_line(char *s)
{
	while (*s == ' ')
		s++;
	if (!ft_strncmp(s, "NO", 2) && s[2] == ' ')
		return (1);
	if (!ft_strncmp(s, "SO", 2) && s[2] == ' ')
		return (1);
	if (!ft_strncmp(s, "WE", 2) && s[2] == ' ')
		return (1);
	if (!ft_strncmp(s, "EA", 2) && s[2] == ' ')
		return (1);
	return (0);
}

static int	color_line(char *s)
{
	while (*s == ' ')
		s++;
	if ((*s == 'F' || *s == 'C') && s[1] == ' ')
		return (1);
	return (0);
}

static int	map_line(char *s)
{
	while (*s == ' ')
		s++;
	return (*s == '1' || *s == '0');
}

static int	take_line(char *s, t_cub_raw *out, int *n)
{
	char	*p;

	p = s;
	while (*p == ' ')
		p++;
	if (*p == '\0')
		return (0);
	if (map_line(p))
		return (1);
	if (text_line(p))
	{
		if (hdr_parse_tex(s, out) == -1)
			return (-1);
		(*n)++;
		return (0);
	}
	if (color_line(p))
	{
		if (hdr_parse_col(s, out) == -1)
			return (-1);
		(*n)++;
		return (0);
	}
	return (error_msg("Invalid Identifier"));
}

int	hdr_stage(char **lines, t_cub_raw *out, int *map_start)
{
	int	i;
	int	n;
	int	r;

	i = 0;
	n = 0;
	*map_start = -1;
	while (lines[i])
	{
		r = take_line(lines[i], out, &n);
		if (r == -1)
			return (-1);
		if (r == 1)
		{
			*map_start = i;
			break ;
		}
		i++;
	}
	if (n != 6)
		return (error_msg("Invalid headers"));
	if (*map_start == -1)
		return (error_msg("No map found"));
	return (0);
}

