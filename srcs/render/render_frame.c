#include "cub.h"

static int	color_to_int(t_color c)
{
	return ((c.r << 16) | (c.g << 8) | c.b);
}

static void	draw_scene_column(t_scene *scene, int x)
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	t_rayhit	hit;
	t_player	*p;

	p = &scene->player;
	camera_x = 2.0 * x / (double)WIN_W - 1.0;
	ray_dir_x = p->dir.x + p->plane.x * camera_x;
	ray_dir_y = p->dir.y + p->plane.y * camera_x;
	hit = cast_single_ray(scene, ray_dir_x, ray_dir_y);
	draw_column_solid(scene, &hit, x);
}

void	render_frame(t_app *app)
{
	int		ceiling_c;
	int		floor_c;
	int		x;
	t_scene	*scene;

	scene = &app->scene;
	ceiling_c = color_to_int(scene->ceiling);
	floor_c = color_to_int(scene->floor);
	frame_clear(&scene->frame, ceiling_c, floor_c);
	x = 0;
	while (x < WIN_W)
	{
		draw_scene_column(scene, x);
		x++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->frame_img, 0, 0);
}

