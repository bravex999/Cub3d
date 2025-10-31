#ifndef ERROR_H
# define ERROR_H

int		error_msg(const char *msg);
int		error_syserr(const char *ctx);
void	error_exit(const char *msg);

#endif
