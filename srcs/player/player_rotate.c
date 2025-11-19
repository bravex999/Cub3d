#include "cub.h"

void	player_rotate_left(t_scene *scene)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = scene->player.dir.x;
	old_plane_x = scene->player.plane.x;
	scene->player.dir.x = scene->player.dir.x * cos(-ROT_SPEED)
		- scene->player.dir.y * sin(-ROT_SPEED);
	scene->player.dir.y = old_dir_x * sin(-ROT_SPEED)
		+ scene->player.dir.y * cos(-ROT_SPEED);
	scene->player.plane.x = scene->player.plane.x * cos(-ROT_SPEED)
		- scene->player.plane.y * sin(-ROT_SPEED);
	scene->player.plane.y = old_plane_x * sin(-ROT_SPEED)
		+ scene->player.plane.y * cos(-ROT_SPEED);
}

void	player_rotate_right(t_scene *scene)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = scene->player.dir.x;
	old_plane_x = scene->player.plane.x;
	scene->player.dir.x = scene->player.dir.x * cos(ROT_SPEED)
		- scene->player.dir.y * sin(ROT_SPEED);
	scene->player.dir.y = old_dir_x * sin(ROT_SPEED)
		+ scene->player.dir.y * cos(ROT_SPEED);
	scene->player.plane.x = scene->player.plane.x * cos(ROT_SPEED)
		- scene->player.plane.y * sin(ROT_SPEED);
	scene->player.plane.y = old_plane_x * sin(ROT_SPEED)
		+ scene->player.plane.y * cos(ROT_SPEED);
}
