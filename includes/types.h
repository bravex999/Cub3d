#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;	

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_ray2d
{
	t_vec2	origin;
	t_vec2	dir;
}	t_ray2d;

typedef struct s_image
{
	int		width;
	int		height;
	void	*pixels;
}	t_image;

typedef struct s_texture
{
	int		width;
	int		height;
	void	*pixels;
}	t_texture;

typedef enum e_tex_id
{
	TEX_NO = 0,
	TEX_SO = 1,
	TEX_WE = 2,
	TEX_EA = 3
}	t_tex_id;

typedef struct s_texture_paths
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture_paths;	

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		spawn_x;
	int		spawn_y;
	char	spawn_dir;
}	t_map;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
}	t_player;

typedef struct s_scene
{
	t_map		map;
	t_player	player;
	t_texture	textures[4];
	t_color		floor;
	t_color		ceiling;
	t_image		frame;
}	t_scene;

typedef struct s_app
{
	void			*mlx;
	void			*win;
	t_scene			scene;
	t_texture_paths	tex_paths;
}	t_app;
#endif
