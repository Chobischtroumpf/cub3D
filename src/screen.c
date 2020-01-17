/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:28:10 by adorigo           #+#    #+#             */
/*   Updated: 2020/01/17 14:01:34 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		set_screen(t_cub3d *cub3d)
{
	if (!(cub3d->mlx = mlx_init()))
		return (err_free(-1, "Failed to init mlx.\n", cub3d, 0));
	if (!(cub3d->win = mlx_new_window(cub3d->mlx,
					cub3d->conf->res_w, cub3d->conf->res_h, "cub3d")))
		return (err_free(-1, "Failed to create mlx window.\n", cub3d, 0));
	// if (!(cub3d->img = mlx_new_image(cub3d->mlx,
	// 	cub3d->conf->res_w, cub3d->conf->res_h)))
	// 	return (err_free(-1, "Failed to init screen buffer.\n", cub3d, 0));
	// if (!(cub3d->data = mlx_get_data_addr(cub3d->img,
	// 	&cub3d->bpp, &cub3d->size_line, &cub3d->endian)))
	// {
	// 	return (err_free(-1,
	// 		"Failed to get data from screen buffer.\n", cub3d, 0));
	// }
	return (1);
}
