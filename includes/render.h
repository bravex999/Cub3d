/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:54:48 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 15:54:50 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
}	t_dda;

typedef struct s_rayhit
{
	double	perp_dist;
	int		side;
	double	ray_dir_x;
	double	ray_dir_y;
}	t_rayhit;

void		render_frame(t_app *app);
t_rayhit	cast_single_ray(t_scene *scene, double ray_dir_x,
				double ray_dir_y);
void		draw_column_solid(t_scene *scene, t_rayhit *hit, int x);
void		init_deltas(double ray_dir_x, double ray_dir_y,
				double *delta_x, double *delta_y);
void		init_steps(t_scene *scene, double ray_dir_x, double ray_dir_y,
				t_dda *dda);
void		step_ray(t_dda *dda, int *side);
int			check_hit(t_scene *scene, t_dda *dda, int *hit);

#endif
