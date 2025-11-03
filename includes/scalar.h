#ifndef SCALAR_H
# define SCALAR_H

# define SC_EPS 1e-12

double	degrees_to_radians(double deg);
double	clamp_d(double x, double lo, double hi);
double	norm2(double x, double y);
void	normalize_pair(double *x, double *y);

#endif
