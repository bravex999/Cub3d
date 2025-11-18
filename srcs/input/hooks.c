#include "cub.h"

static void	destroy_images(t_app *app)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (app->scene.textures[i].img)
			mlx_destroy_image(app->mlx, app->scene.textures[i].img);
		i++;
	}
	if (app->frame_img)
		mlx_destroy_image(app->mlx, app->frame_img);
}

int	app_close_window(t_app *app)
{
	if (!app)
		return (0);
	destroy_images(app);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	/*cleanup general
	 *cleanup */
	exit(0);
	return (0);
}

int	app_key_press(int keycode, t_app *app)
{
	if (!app)
		return (0);
	if (keycode == XK_w)
		app->keys.w = 1;
	else if (keycode == XK_a)
		app->keys.a = 1;
	else if (keycode == XK_s)
		app->keys.s = 1;
	else if (keycode == XK_d)
		app->keys.d = 1;
	else if (keycode == XK_Left)
		app->keys.left = 1;
	else if (keycode == XK_Right)
		app->keys.right = 1;
	else if (keycode == XK_Escape)
		app_close_window(app);
	return (0);
}

int	app_key_release(int keycode, t_app *app)
{
	if (!app)
		return (0);
	if (keycode == XK_w)
		app->keys.w = 0;
	else if (keycode == XK_a)
		app->keys.a = 0;
	else if (keycode == XK_s)
		app->keys.s = 0;
	else if (keycode == XK_d)
		app->keys.d = 0;
	else if (keycode == XK_Left)
		app->keys.left = 0;
	else if (keycode == XK_Right)
		app->keys.right = 0;
	return (0);
}

int	app_update(t_app *app)
{
	t_scene	*scene;

	if (!app)
		return (0);
	scene = &app->scene;
	if (app->keys.w)
		player_move_forward(scene);
	if (app->keys.s)
		player_move_backward(scene);
	if (app->keys.a)
		player_strafe_left(scene);
	if (app->keys.d)
		player_strafe_right(scene);
	if (app->keys.left)
		player_rotate_left(scene);
	if (app->keys.right)
		player_rotate_right(scene);
	render_frame(app);
	return (0);
}
