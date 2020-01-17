/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:08:20 by adorigo           #+#    #+#             */
/*   Updated: 2020/01/17 09:30:13 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		msg_err(int erno, char *msg, int ret)
{
    write(STDERR_FILENO, "Error:\n", 7);
	if (erno < 0)
		ft_putstr_fd(msg, STDERR_FILENO);
	else
		strerror(errno);
	return(ret);
}

int		err_free(int erno, char *msg, t_cub3d *cub3d, int ret)
{
	msg_err(erno, msg, ret);
	return(free_all(cub3d, ret));
}
