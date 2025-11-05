#include "cub.h"

static int	apply_tex(const char *path_str, t_headers *h,
			char **slot, int bit)
{
	char	*path;
	int		i;

	if (h->seen_mask & bit)
		return (-1);
	i = 0;
	skip_spaces_plus(path_str, &i);
	path = dup_trim_tail(path_str, i);
	if (path == NULL)
		return (-1);
	*slot = path;
	h->seen_mask |= bit;
	return (1);
}

int	try_texture_no(const char *str, t_headers *h)
{
	int	i;

	i = 0;
	skip_spaces_plus(str, &i);
	if (!match_token(str, i, "NO"))
		return (0);
	i += 2;
	skip_spaces_plus(str, &i);
	return (apply_tex(&str[i], h, &h->tex_no, HDR_NO));
}

int	try_texture_so(const char *str, t_headers *h)
{
	int	i;

	i = 0;
	skip_spaces_plus(str, &i);
	if (!match_token(str, i, "SO"))
		return (0);
	i += 2;
	skip_spaces_plus(str, &i);
	return (apply_tex(&str[i], h, &h->tex_so, HDR_SO));
}

int	try_texture_we(const char *str, t_headers *h)
{
	int	i;

	i = 0;
	skip_spaces_plus(str, &i);
	if (!match_token(str, i, "WE"))
		return (0);
	i += 2;
	skip_spaces_plus(str, &i);
	return (apply_tex(&str[i], h, &h->tex_we, HDR_WE));
}

int	try_texture_ea(const char *str, t_headers *h)
{
	int	i;

	i = 0;
	skip_spaces_plus(str, &i);
	if (!match_token(str, i, "EA"))
		return (0);
	i += 2;
	skip_spaces_plus(str, &i);
	return (apply_tex(&str[i], h, &h->tex_ea, HDR_EA));
}
