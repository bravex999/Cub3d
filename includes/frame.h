/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:51:26 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 15:51:28 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

void	frame_put_pixel(t_image *frame, int x, int y, int color);
void	frame_clear(t_image *frame, int ceiling_c, int floor_c);

#endif
