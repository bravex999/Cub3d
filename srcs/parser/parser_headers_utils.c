#include "cub.h"

int	match_token(const char *str, int index, const char *tok)
{
	int	i;

	i = 0;
	while (tok[i] && str[index + i] == tok[i])
		i++;
	if (tok[i] != '\0')
		return (0);
	if (str[index + i] != ' ' && str[index + i] != '\t')
		return (0);
	return (1);
}

char	*dup_trim_tail(const char *str, int start)
{
	int		end;
	int		len;
	int		i;
	char	*out;

	end = start;
	while (str[end] && str[end] != '\n')
		end++;
	while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
		end--;
	len = end - start;
	if (len <= 0)
		return (NULL);
	out = (char *)malloc((unsigned int)len + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = str[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
