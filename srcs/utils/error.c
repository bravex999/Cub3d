/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnaranj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:22:23 by chnaranj          #+#    #+#             */
/*   Updated: 2025/12/22 16:22:25 by chnaranj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

int	error_msg(const char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd((char *)msg, 2);
	return (-1);
}

int	error_syserr(const char *ctx)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd((char *)ctx, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd((char *)strerror(errno), 2);
	return (-1);
}

void	error_exit(const char *msg)
{
	(void)error_msg(msg);
	exit(EXIT_FAILURE);
}
