/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:58:41 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 15:58:43 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	free_cub_raw(t_cub_raw *raw)
{
	int	y;

	if (!raw)
		return ;
	if (raw->map)
	{
		y = 0;
		while (y < raw->map_h)
		{
			free(raw->map[y]);
			y++;
		}
		free(raw->map);
	}
	if (raw->tex_no)
		free(raw->tex_no);
	if (raw->tex_so)
		free(raw->tex_so);
	if (raw->tex_we)
		free(raw->tex_we);
	if (raw->tex_ea)
		free(raw->tex_ea);
}

int	free_error(t_cub_raw *raw, t_app *app)
{
	if (app)
		app_destroy(app);
	if (raw)
		free_cub_raw(raw);
	return (1);
}
