/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:12:51 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 16:12:52 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	has_cub_ext(const char *path)
{
	int	len;

	if (!path)
		return (0);
	len = (int)ft_strlen(path);
	if (len <= 4)
		return (0);
	return (ft_strncmp(path + len - 4, ".cub", 4) == 0);
}

int	parse_precheck(const char *path)
{
	int	fd;

	if (!has_cub_ext(path))
		return (error_msg("Map file must have .cub extension"));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_msg("Could not open map"));
	close(fd);
	return (0);
}
