/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:18:59 by adorigo           #+#    #+#             */
/*   Updated: 2020/02/10 15:29:02 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			err_msg(int erno, char *msg, int ret)
{
	write(STDERR_FILENO, "Error:\n", 7);
	if (erno < 0)
		ft_putstr_fd(msg, STDERR_FILENO);
	else
		strerror(errno);
	return (ret);
}

int			err_free(int erno, char *msg, t_cub3d *cub3d, int ret)
{
	err_msg(erno, msg, ret);
	free_all(cub3d, ret);
	exit(-1);
}
