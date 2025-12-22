/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_back_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:08:19 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 16:08:22 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "frame.h"

void	frame_put_pixel(t_image *frame, int x, int y, int color)
{
	unsigned int	*buf;

	if (!frame || !frame->pixels)
		return ;
	if (x < 0 || x >= frame->width)
		return ;
	if (y < 0 || y >= frame->height)
		return ;
	buf = (unsigned int *)frame->pixels;
	buf[y * frame->width + x] = (unsigned int)color;
}

static void	frame_fill_half(t_image *frame, int color,
			int start_y, int end_y)
{
	int	x;
	int	y;

	y = start_y;
	while (y < end_y)
	{
		x = 0;
		while (x < frame->width)
		{
			frame_put_pixel(frame, x, y, color);
			x++;
		}
		y++;
	}
}

void	frame_clear(t_image *frame, int ceiling_c, int floor_c)
{
	int	half;

	if (!frame || !frame->pixels)
		return ;
	half = frame->height / 2;
	frame_fill_half(frame, ceiling_c, 0, half);
	frame_fill_half(frame, floor_c, half, frame->height);
}
