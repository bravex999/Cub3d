#include "cub.h"

int	is_valid_cell(t_scene *scene, double x, double y)
{
	int		map_x;
	int		map_y;
	char	cell;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0)
		return (0);
	if (map_x >= scene->map.width || map_y >= scene->map.height)
		return (0);
	cell = scene->map.grid[map_y][map_x];
	if (cell == '1')
		return (0);
	return (1);
}

void	player_move_forward(t_scene *scene)
{
	double	new_x;
	double	new_y;

	new_x = scene->player.pos.x + scene->player.dir.x * MOVE_SPEED;
	new_y = scene->player.pos.y + scene->player.dir.y * MOVE_SPEED;
	if (is_valid_cell(scene, new_x, scene->player.pos.y))
		scene->player.pos.x = new_x;
	if (is_valid_cell(scene, scene->player.pos.x, new_y))
		scene->player.pos.y = new_y;
}

void	player_move_backward(t_scene *scene)
{
	double	new_x;
	double	new_y;

	new_x = scene->player.pos.x - scene->player.dir.x * MOVE_SPEED;
	new_y = scene->player.pos.y - scene->player.dir.y * MOVE_SPEED;
	if (is_valid_cell(scene, new_x, scene->player.pos.y))
		scene->player.pos.x = new_x;
	if (is_valid_cell(scene, scene->player.pos.x, new_y))
		scene->player.pos.y = new_y;
}

void	player_strafe_left(t_scene *scene)
{
	double	new_x;
	double	new_y;

	new_x = scene->player.pos.x - scene->player.plane.x * MOVE_SPEED;
	new_y = scene->player.pos.y - scene->player.plane.y * MOVE_SPEED;
	if (is_valid_cell(scene, new_x, scene->player.pos.y))
		scene->player.pos.x = new_x;
	if (is_valid_cell(scene, scene->player.pos.x, new_y))
		scene->player.pos.y = new_y;
}

void	player_strafe_right(t_scene *scene)
{
	double	new_x;
	double	new_y;

	new_x = scene->player.pos.x + scene->player.plane.x * MOVE_SPEED;
	new_y = scene->player.pos.y + scene->player.plane.y * MOVE_SPEED;
	if (is_valid_cell(scene, new_x, scene->player.pos.y))
		scene->player.pos.x = new_x;
	if (is_valid_cell(scene, scene->player.pos.x, new_y))
		scene->player.pos.y = new_y;
}
