/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:14:02 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 16:14:03 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	lines_free(char **v)
{
	int	i;

	if (!v)
		return ;
	i = 0;
	while (v[i])
		free(v[i++]);
	free(v);
}

static int	file_lines(const char *path)
{
	int		fd;
	int		n;
	char	*ln;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	n = 0;
	ln = get_next_line(fd);
	while (ln)
	{
		free(ln);
		n++;
		ln = get_next_line(fd);
	}
	close(fd);
	return (n);
}

static void	trim_nl(char *s)
{
	int	l;

	if (!s)
		return ;
	l = (int)ft_strlen(s);
	if (l > 0 && s[l - 1] == '\n')
		s[l - 1] = '\0';
}

static char	**read_lines(const char *path)
{
	int		fd;
	int		i;
	int		total;
	char	*ln;
	char	**v;

	total = file_lines(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	v = (char **)ft_calloc(total + 1, sizeof(char *));
	if (!v)
		return (close(fd), NULL);
	i = 0;
	ln = get_next_line(fd);
	while (ln)
	{
		trim_nl(ln);
		v[i++] = ln;
		ln = get_next_line(fd);
	}
	close(fd);
	return (v);
}

int	parse_cub(const char *path, t_cub_raw *out)
{
	char	**lines;
	int		map_start;

	if (!path || !out)
		return (-1);
	if (parse_precheck(path) == -1)
		return (-1);
	init_cub_raw(out);
	lines = read_lines(path);
	if (!lines)
		return (error_msg("incorrect map"));
	if (hdr_stage(lines, out, &map_start) == -1)
		return (lines_free(lines), -1);
	if (map_stage(lines, map_start, out) == -1)
		return (lines_free(lines), -1);
	lines_free(lines);
	return (0);
}
