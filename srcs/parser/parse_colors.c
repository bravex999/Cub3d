#include "cub.h"

static void	skip_spaces_plus(const char *str, int *index)
{
	while (str[*index] == ' ' || str[*index] == '\t')
		(*index)++;
}

static int	parse_color_number_plus(const char *str, int *index, int *out)
{
	int	v;
	int	has;

	skip_spaces_plus(str, index);
	v = 0;
	has = 0;
	while (str[*index] && ft_isdigit((unsigned char)str[*index]))
	{
		has = 1;
		v = v * 10 + (str[*index] - '0');
		if (v > 255)
			return (-1);
		(*index)++;
	}
	if (!has)
		return (-1);
	*out = v;
	return (0);
}

const char	*skip_spaces(const char *str)
{
	int	index;

	index = 0;
	skip_spaces_plus(str, &index);
	return (str + index);
}

int	parse_rgb(const char *str, int *r, int *g, int *b)
{
	int	index;

	index = 0;
	if (parse_color_number_plus(str, &index, r) < 0)
		return (-1);
	skip_spaces_plus(str, &index);
	if (str[index] != ',')
		return (-1);
	index++;
	if (parse_color_number_plus(str, &index, g) < 0)
		return (-1);
	skip_spaces_plus(str, &index);
	if (str[index] != ',')
		return (-1);
	index++;
	if (parse_color_number_plus(str, &index, b) < 0)
		return (-1);
	skip_spaces_plus(str, &index);
	if (str[index] != '\0')
		return (-1);
	return (0);
}
