#ifndef PLAYER_H
# define PLAYER_H

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05

int		is_valid_cell(t_scene *scene, double x, double y);
void	player_move_forward(t_scene *scene);
void	player_move_backward(t_scene *scene);
void	player_strafe_left(t_scene *scene);
void	player_strafe_right(t_scene *scene);
void	player_rotate_left(t_scene *scene);
void	player_rotate_right(t_scene *scene);

#endif

