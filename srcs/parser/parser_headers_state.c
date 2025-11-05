#include "cub.h"

void	headers_init(t_headers *h)
{
	h->tex_no = NULL;
	h->tex_so = NULL;
	h->tex_we = NULL;
	h->tex_ea = NULL;
	h->f_r = 0;
	h->f_g = 0;
	h->f_b = 0;
	h->c_r = 0;
	h->c_g = 0;
	h->c_b = 0;
	h->seen_mask = 0;
}

void	headers_free(t_headers *h)
{
	if (h->tex_no)
		free(h->tex_no);
	if (h->tex_so)
		free(h->tex_so);
	if (h->tex_we)
		free(h->tex_we);
	if (h->tex_ea)
		free(h->tex_ea);
	h->tex_no = NULL;
	h->tex_so = NULL;
	h->tex_we = NULL;
	h->tex_ea = NULL;
}

int	headers_complete(const t_headers *h)
{
	if ((h->seen_mask & HDR_ALL) == HDR_ALL)
		return (1);
	return (0);
}
