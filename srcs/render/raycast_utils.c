#include <cub.h>

void	init_deltas(double ray_dir_x, double ray_dir_y,
			double *delta_x, double *delta_y)
{
	if (fabs(ray_dir_x) < 1e-6)
		ray_dir_x = 1e-6;
	if (fabs(ray_dir_y) < 1e-6)
		ray_dir_y = 1e-6;
	*delta_x = fabs(1.0 / ray_dir_x);
	*delta_y = fabs(1.0 / ray_dir_y);
}

void	init_steps(t_scene *scene, double ray_dir_x, double ray_dir_y,
			t_dda *dda)
{
	t_vec2	pos;

	pos = scene->player.pos;
	if (ray_dir_x < 0.0)
	{
		dda->step_x = -1;
		dda->side_x = (pos.x - dda->map_x) * dda->delta_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_x = (dda->map_x + 1.0 - pos.x) * dda->delta_x;
	}
	if (ray_dir_y < 0.0)
	{
		dda->step_y = -1;
		dda->side_y = (pos.y - dda->map_y) * dda->delta_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_y = (dda->map_y + 1.0 - pos.y) * dda->delta_y;
	}
}

void	step_ray(t_dda *dda, int *side)
{
	if (dda->side_x < dda->side_y)
	{
		dda->side_x += dda->delta_x;
		dda->map_x += dda->step_x;
		*side = 0;
	}
	else
	{
		dda->side_y += dda->delta_y;
		dda->map_y += dda->step_y;
		*side = 1;
	}
}

int	check_hit(t_scene *scene, t_dda *dda, int *hit)
{
	char	cell;

	cell = scene->map.grid[dda->map_y][dda->map_x];
	if (cell == '1')
	{
		*hit = 1;
		return (1);
	}
	return (0);
}

