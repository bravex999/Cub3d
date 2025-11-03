#include "cub.h"

void	normalize_pair(double *x, double *y)
{
	double len;

	len = norm2(*x, *y);
	if (len < SC_EPS)
	{
		*x = 0.0;
		*y = 0.0;
		return;
	}
	*x /= len;
	*y /= len;
}	
