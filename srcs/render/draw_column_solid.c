#include "cub.h"

static int	get_wall_color(t_rayhit *hit)
{
	if (hit->side == 0)
		return (0x777777);
	return (0x555555);
}

void	draw_column_solid(t_scene *scene, t_rayhit *hit, int x)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		y;
	int		color;

	line_height = (int)(scene->frame.height / hit->perp_dist);
	if (line_height > scene->frame.height * 10)
		line_height = scene->frame.height * 10;
	draw_start = -line_height / 2 + scene->frame.height / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + scene->frame.height / 2;
	if (draw_end >= scene->frame.height)
		draw_end = scene->frame.height - 1;
	color = get_wall_color(hit);
	y = draw_start;
	while (y <= draw_end)
	{
		frame_put_pixel(&scene->frame, x, y, color);
		y++;
	}
}

