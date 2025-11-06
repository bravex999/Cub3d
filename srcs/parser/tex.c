#include "cub.h"

static void	split_free(char **v)
{
	int	i;

	if (!v)
		return ;
	i = 0;
	while (v[i])
		free(v[i++]);
	free(v);
}

static int	is_xpm(const char *p)
{
	int	l;

	if (!p)
		return (0);
	l = (int)ft_strlen(p);
	if (l < 5)
		return (0);
	if (p[l - 4] != '.' || p[l - 3] != 'x'
		|| p[l - 2] != 'p' || p[l - 1] != 'm')
		return (0);
	return (1);
}

static int	tex_assign(char **dst, const char *path)
{
	if (*dst)
		return (-1);
	*dst = ft_strdup(path);
	if (!*dst)
		return (-1);
	return (0);
}

static int	tex_save(t_cub_raw *o, char *key, char *path)
{
	if (!ft_strncmp(key, "NO", 3))
		return (tex_assign(&o->tex_no, path));
	if (!ft_strncmp(key, "SO", 3))
		return (tex_assign(&o->tex_so, path));
	if (!ft_strncmp(key, "WE", 3))
		return (tex_assign(&o->tex_we, path));
	if (!ft_strncmp(key, "EA", 3))
		return (tex_assign(&o->tex_ea, path));
	return (-1);
}

int	hdr_parse_tex(char *line, t_cub_raw *out)
{
	char	**sp;
	int		fd;
	int		ret;

	if (!line || !out)
		return (-1);
	sp = ft_split(line, ' ');
	if (!sp || !sp[0] || !sp[1] || sp[2])
		return (split_free(sp), -1);
	if (!is_xpm(sp[1]))
		return (split_free(sp), -1);
	fd = open(sp[1], O_RDONLY);
	if (fd < 0)
		return (split_free(sp), -1);
	close(fd);
	ret = tex_save(out, sp[0], sp[1]);
	split_free(sp);
	return (ret);
}

