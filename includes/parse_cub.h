#ifndef PARSE_CUB_H
# define PARSE_CUB_H

typedef struct s_cub_raw
{
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	char	**map;
	int		map_w;
	int		map_h;
}	t_cub_raw;

void	init_cub_raw(t_cub_raw *out);
int		parse_cub(const char *path, t_cub_raw *out);
int		hdr_stage(char **lines, t_cub_raw *out, int *map_start);
int		hdr_parse_tex(char *line, t_cub_raw *out);
int		hdr_parse_col(char *line, t_cub_raw *out);
int		map_stage(char **lines, int map_start, t_cub_raw *out);
int		map_check_charset(char **blk);
int		map_scan_spawn(char **blk, int pos[2], char *dir);
int		map_alloc_rect(t_cub_raw *out, int w, int h);
int		map_copy_rect(char **src, char **dst, int w, int h);
int		map_is_closed(char **m, int w, int h);
