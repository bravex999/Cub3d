#include "cub.h"

static int is_space(char c)
{
	if(c == ' ' || c == '\t' || c == '\r')
		return (1);
	return (0);
}

static int has2(const char *str, char a, char b)
{
	return (str[0] == a && str[1] == b);
}

int is_blank(const char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (!is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int is_header_line(const char *str)
{
	int i;
	i = 0;
	
	while(str[i] && is_space(str[i]))
		i++;
	if(has2(&str[i], 'N', 'O') || has2(&str[i], 'S', 'O'))
		return (1);
	if(has2(&str[i], 'W', 'E') || has2(&str[i], 'E', 'A'))
		return (1);
	if((str[i] == 'F' && is_space(str[i + 1]))
		|| (str[i] == 'C' && is_space(str[i + 1])))
		return (1);
	return (0);
}

int is_map_line(const char *str)
{
	int i;
	int seen;

	i = 0;
	seen = 0;
	while(str[i] && is_space(str[i]))
		i++;
	while (str[i])
	{
		if(str[i] == '0' || str[i] == '1')
			seen = 1;
		else if (str[i] == ' ' || str[i] == 'N' || str[i] == 'S'
			|| str[i] == 'E' || str[i] == 'W')
			;
		else
			return (0);
		i++;
	}
	return (seen);
}	
























		









