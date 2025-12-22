/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:52:15 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 15:52:17 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

int	app_key_press(int keycode, t_app *app);
int	app_key_release(int keycode, t_app *app);
int	app_update(t_app *app);
int	app_close_window(t_app *app);

#endif
