#include "cub.h"

static int	set_path(char **dst, const char *str)
{
	*dst = ft_strdup(str);
	if (!*dst)
		return (-1);
	return (0);
}

void	free_paths(t_cub_raw *cr)
{
	if (cr->tex_no)
		free(cr->tex_no);
	if (cr->tex_so)
		free(cr->tex_so);
	if (cr->tex_we)
		free(cr->tex_we);
	if (cr->tex_ea)
		free(cr->tex_ea);
	cr->tex_no = NULL;
	cr->tex_so = NULL;
	cr->tex_we = NULL;
	cr->tex_ea = NULL;
}

static int	copy_paths(t_cub_raw *out, const t_headers *h)
{
	if (set_path(&out->tex_no, h->tex_no) < 0)
		return (-1);
	if (set_path(&out->tex_so, h->tex_so) < 0)
	{
		free_paths(out);
		return (-1);
	}
	if (set_path(&out->tex_we, h->tex_we) < 0)
	{
		free_paths(out);
		return (-1);
	}
	if (set_path(&out->tex_ea, h->tex_ea) < 0)
	{
		free_paths(out);
		return (-1);
	}
	return (0);
}

void	cub_raw_init(t_cub_raw *out)
{
	out->tex_no = NULL;
	out->tex_so = NULL;
	out->tex_we = NULL;
	out->tex_ea = NULL;
	out->f_r = 0;
	out->f_g = 0;
	out->f_b = 0;
	out->c_r = 0;
	out->c_g = 0;
	out->c_b = 0;
	map_init(&out->map);
	out->map_h = 0;
}

int	cub_raw_set_headers(t_cub_raw *out, const t_headers *h)
{
	if (copy_paths(out, h) < 0)
		return (-1);
	out->f_r = h->f_r;
	out->f_g = h->f_g;
	out->f_b = h->f_b;
	out->c_r = h->c_r;
	out->c_g = h->c_g;
	out->c_b = h->c_b;
	return (0);
}
