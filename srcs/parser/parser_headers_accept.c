#include "cub.h"

int	headers_accept_line(const char *str, t_headers *h)
{
	int	ret;

	ret = try_texture_no(str, h);
	if (ret != 0)
		return (ret);
	ret = try_texture_so(str, h);
	if (ret != 0)
		return (ret);
	ret = try_texture_we(str, h);
	if (ret != 0)
		return (ret);
	ret = try_texture_ea(str, h);
	if (ret != 0)
		return (ret);
	ret = try_floor_color(str, h);
	if (ret != 0)
		return (ret);
	ret = try_ceiling_color(str, h);
	return (ret);
}
