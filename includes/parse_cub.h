#ifndef PARSE_CUB_H
# define PARSE_CUB_H

/*detectors*/
int			is_blank(const char *str);
int			is_header_line(const char *str);
int			is_map_line(const char *str);

/*colors*/
const char	*skip_spaces(const char *str);
void		skip_spaces_plus(const char *str, int *index);
int			parse_rgb(const char *str, int *r, int *g, int *b);

/*headers*/
void		headers_init(t_headers *h);
void		headers_free(t_headers *h);
int			headers_complete(const t_headers *h);
int			headers_accept_line(const char *str, t_headers *h);

#endif
