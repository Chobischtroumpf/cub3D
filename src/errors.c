/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:00:59 by adorigo           #+#    #+#             */
/*   Updated: 2020/01/27 09:05:25 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_msg(int erno, char *msg, int ret)
{
	write(STDERR_FILENO, "Error:\n", 7);
	if (erno < 0)
		ft_putstr_fd(msg, STDERR_FILENO);
	else
		strerror(errno);
	return (ret);
}

int	err_free(int erno, char *msg, t_cub3d *cub3d, int ret)
{
	err_msg(erno, msg, ret);
	return (free_all(cub3d, ret));
}
