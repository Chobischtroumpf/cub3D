/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 08:18:28 by adorigo           #+#    #+#             */
/*   Updated: 2020/06/09 11:18:29 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		calc_side_dist(t_pos *side, t_pos *delta, int map[], int step[])
{
	if (side->x < side->y)
	{
		side->x += delta->x;
		map[0] += step[0];
		return (1);
	}
	else
	{
		side->y += delta->y;
		map[1] += step[1];
		return (0);
	}
}

double	deg2rad(double deg)
{
	return (deg / 180 * M_PI);
}

void	render(t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img, 0, 0);
}
