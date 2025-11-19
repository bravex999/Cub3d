#include "cub.h"

static void	scene_init_ns(t_player *pl, char dir)
{
	if (dir == 'N')
	{
		pl->dir.x = 0.0;
		pl->dir.y = -1.0;
		pl->plane.x = 0.66;
		pl->plane.y = 0.0;
	}
	else
	{
		pl->dir.x = 0.0;
		pl->dir.y = 1.0;
		pl->plane.x = -0.66;
		pl->plane.y = 0.0;
	}
}

static void	scene_init_ew(t_player *pl, char dir)
{
	if (dir == 'E')
	{
		pl->dir.x = 1.0;
		pl->dir.y = 0.0;
		pl->plane.x = 0.0;
		pl->plane.y = 0.66;
	}
	else
	{
		pl->dir.x = -1.0;
		pl->dir.y = 0.0;
		pl->plane.x = 0.0;
		pl->plane.y = -0.66;
	}
}

void	scene_init_dir(t_player *pl, char dir)
{
	if (dir == 'N' || dir == 'S')
		scene_init_ns(pl, dir);
	else
		scene_init_ew(pl, dir);
}
