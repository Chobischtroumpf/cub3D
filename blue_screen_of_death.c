/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_screen_of_death.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:05:35 by adorigo           #+#    #+#             */
/*   Updated: 2019/12/12 15:53:26 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int blue_screen_of_death( void *mlx_ptr, void *win_ptr, int x, int y)
{
	int y2 = 0;
	int x2 = 0;

    while(y >= y2)
    {
		x2 = 0;
        while(x >= x2)
		{
			mlx_pixel_put( mlx_ptr, win_ptr, y2, x2, 0255255255);
			x2++;
		}
		y2++;
    }
	return (0);
}