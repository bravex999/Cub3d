#ifndef PARSE_CUB_H
# define PARSE_CUB_H

# define HDR_NO 1
# define HDR_SO 2
# define HDR_WE 4
# define HDR_EA 8
# define HDR_F  16
# define HDR_C  32

typedef struct s_headers
{
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	int		seen_mask;
}	t_headers;

/* detectors */
int			is_blank(const char *str);
int			is_header_line(const char *str);
int			is_map_line(const char *str);

/* colors */
const char	*skip_spaces(const char *str);
void		skip_spaces_plus(const char *str, int *index);
int			parse_rgb(const char *str, int *r, int *g, int *b);

/* headers*/
void		headers_init(t_headers *h);
void		headers_free(t_headers *h);
int			headers_complete(const t_headers *h);
int			headers_accept_line(const char *str, t_headers *h);

/* helpers */
int			match_token(const char *str, int index, const char *tok);
char		*dup_trim_tail(const char *str, int start);
int			try_texture_no(const char *str, t_headers *h);
int			try_texture_so(const char *str, t_headers *h);
int			try_texture_we(const char *str, t_headers *h);
int			try_texture_ea(const char *str, t_headers *h);
int			try_floor_color(const char *str, t_headers *h);
int			try_ceiling_color(const char *str, t_headers *h);

/* map buffer */
typedef struct s_map_buffer
{
	char	**lines;
	int		count;
	int		cap;
}			t_map_buffer;

void		map_init(t_map_buffer *map);
int			map_push(t_map_buffer *map, const char *str);
void		map_free(t_map_buffer *map);

/* parser output */
typedef struct s_cub_raw
{
	char			*tex_no;
	char			*tex_so;
	char			*tex_we;
	char			*tex_ea;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c_r;
	int				c_g;
	int				c_b;
	t_map_buffer	map;
	int				map_h;
}				t_cub_raw;

void		cub_raw_init(t_cub_raw *out);
int			cub_raw_set_headers(t_cub_raw *out, const t_headers *h);
int			cub_raw_take_map(t_cub_raw *out, t_map_buffer *map);
void		free_cub_raw(t_cub_raw *cr);
void		free_paths(t_cub_raw *cr);

#endif
