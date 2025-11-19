#ifndef TEXTURES_H
# define TEXTURES_H

# include "types.h"

/*
carga texturas usando las rutas que hay en app->tex_paths.
*/
typedef struct s_app	t_app;

int	app_load_textures(t_app *app);

#endif
