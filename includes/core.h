#ifndef CORE_H
# define CORE_H

int		scene_init_from_raw(t_scene *scene, const t_cub_raw *raw);
void	scene_init_dir(t_player *pl, char dir);
int		app_init_gfx(t_app *app);
int		app_init_from_raw(t_app *app, const t_cub_raw *raw);
void    app_destroy(t_app *app);
int		free_error(t_cub_raw *raw, t_app *app);


#endif
