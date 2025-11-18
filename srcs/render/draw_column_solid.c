#include <math.h>
#include "cub.h"
#include "frame.h"
#include "render.h"

typedef struct s_colctx
{
	int	line_height;
	int	start;
	int	end;
	int	tex_x;
}	t_colctx;

static t_tex_id	get_tex_id(t_rayhit *hit)
{
	if (hit->side == 0)
	{
		if (hit->ray_dir_x > 0.0)
			return (TEX_EA);
		return (TEX_WE);
	}
	if (hit->ray_dir_y > 0.0)
		return (TEX_SO);
	return (TEX_NO);
}

static void	init_ctx(t_scene *scene, t_rayhit *hit,
				t_texture *tex, t_colctx *ctx)
{
	int		half;
	double	wall_x;

	ctx->line_height = (int)(scene->frame.height / hit->perp_dist);
	if (ctx->line_height > scene->frame.height * 10)
		ctx->line_height = scene->frame.height * 10;
	half = scene->frame.height / 2;
	ctx->start = -ctx->line_height / 2 + half;
	if (ctx->start < 0)
		ctx->start = 0;
	ctx->end = ctx->line_height / 2 + half;
	if (ctx->end >= scene->frame.height)
		ctx->end = scene->frame.height - 1;
	if (hit->side == 0)
		wall_x = scene->player.pos.y
			+ hit->perp_dist * hit->ray_dir_y;
	else
		wall_x = scene->player.pos.x
			+ hit->perp_dist * hit->ray_dir_x;
	wall_x -= floor(wall_x);
	ctx->tex_x = (int)(wall_x * (double)tex->width);
	if (ctx->tex_x < 0)
		ctx->tex_x = 0;
	if (ctx->tex_x >= tex->width)
		ctx->tex_x = tex->width - 1;
}

static int	sample_tex_color(t_texture *tex, int tex_x, int tex_y)
{
	char			*ptr;
	unsigned int	color;

	ptr = (char *)tex->pixels + tex_y * tex->line_len
		+ tex_x * (tex->bpp / 8);
	color = *(unsigned int *)ptr;
	return ((int)color);
}

static void	draw_tex_column(t_scene *scene, t_texture *tex,
				t_colctx *ctx, int x)
{
	int	y;
	int	tex_y;
	int	color;

	y = ctx->start;
	while (y <= ctx->end)
	{
		tex_y = (y - ctx->start) * tex->height / ctx->line_height;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		color = sample_tex_color(tex, ctx->tex_x, tex_y);
		frame_put_pixel(&scene->frame, x, y, color);
		y++;
	}
}

void	draw_column_solid(t_scene *scene, t_rayhit *hit, int x)
{
	t_tex_id	tex_id;
	t_texture	*tex;
	t_colctx	ctx;

	tex_id = get_tex_id(hit);
	tex = &scene->textures[tex_id];
	init_ctx(scene, hit, tex, &ctx);
	draw_tex_column(scene, tex, &ctx, x);
}

