#include "cub.h"

int	try_floor_color(const char *str, t_headers *h)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	skip_spaces_plus(str, &i);
	if (!match_token(str, i, "F"))
		return (0);
	if (h->seen_mask & HDR_F)
		return (-1);
	i += 1;
	skip_spaces_plus(str, &i);
	if (parse_rgb(&str[i], &r, &g, &b) < 0)
		return (-1);
	h->f_r = r;
	h->f_g = g;
	h->f_b = b;
	h->seen_mask |= HDR_F;
	return (1);
}

int	try_ceiling_color(const char *str, t_headers *h)
{
	int	i;
	int	r;
	int	g;
	int	b;

	i = 0;
	skip_spaces_plus(str, &i);
	if (!match_token(str, i, "C"))
		return (0);
	if (h->seen_mask & HDR_C)
		return (-1);
	i += 1;
	skip_spaces_plus(str, &i);
	if (parse_rgb(&str[i], &r, &g, &b) < 0)
		return (-1);
	h->c_r = r;
	h->c_g = g;
	h->c_b = b;
	h->seen_mask |= HDR_C;
	return (1);
}
