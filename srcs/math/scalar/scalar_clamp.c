#include "cub.h"

double	clamp_d(double x, double lo, double hi)
{
	if (x < lo)
		return (lo);
	if (x > hi)
		return (hi);
	return (x);
}	
