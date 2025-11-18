#ifndef INPUT_H
# define INPUT_H

int	app_key_press(int keycode, t_app *app);
int	app_key_release(int keycode, t_app *app);
int	app_update(t_app *app);
int	app_close_window(t_app *app);

#endif

