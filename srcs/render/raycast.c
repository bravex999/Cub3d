#include "cub.h"

static void	perform_dda(t_scene *scene, t_dda *dda, int *side)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (dda->map_x < 0 || dda->map_x >= scene->map.width)
			break ;
		if (dda->map_y < 0 || dda->map_y >= scene->map.height)
			break ;
		step_ray(dda, side);
		if (dda->map_x < 0 || dda->map_x >= scene->map.width)
			break ;
		if (dda->map_y < 0 || dda->map_y >= scene->map.height)
			break ;
		check_hit(scene, dda, &hit);
	}
}

t_rayhit	cast_single_ray(t_scene *scene,
				double ray_dir_x, double ray_dir_y)
{
	t_dda		dda;
	t_rayhit	hit;
	t_vec2		pos;
	int			side;

	pos = scene->player.pos;
	dda.map_x = (int)pos.x;
	dda.map_y = (int)pos.y;
	init_deltas(ray_dir_x, ray_dir_y, &dda.delta_x, &dda.delta_y);
	init_steps(scene, ray_dir_x, ray_dir_y, &dda);
	perform_dda(scene, &dda, &side);
	if (side == 0)
		hit.perp_dist = (dda.map_x - pos.x + (1 - dda.step_x) / 2.0)
			/ ray_dir_x;
	else
		hit.perp_dist = (dda.map_y - pos.y + (1 - dda.step_y) / 2.0)
			/ ray_dir_y;
	if (hit.perp_dist < 0.0001)
		hit.perp_dist = 0.0001;
	hit.side = side;
	hit.ray_dir_x = ray_dir_x;
	hit.ray_dir_y = ray_dir_y;
	return (hit);
}
