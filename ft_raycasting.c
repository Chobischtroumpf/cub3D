/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:34:34 by adorigo           #+#    #+#             */
/*   Updated: 2020/01/14 13:14:57 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub3d	*ft_set_pos(t_cub3d *cub3d, int **world_map)
{
	int i;
	int j;
	while (world_map[i++])
	{
		j = 0;
		while(world_map[i][j])
		{
			if (world_map[i][j] == 6)
			{
				cub3d->player->pos->x = i;
				cub3d->player->pos->y = j;
				cub3d->player->dir->x = -1;
				return (cub3d);
			}
			if (world_map[i][j] == 7)
			{
				cub3d->player->pos->x = i;
				cub3d->player->pos->y = j;
				cub3d->player->dir->x = 1;
				return (cub3d);
			}
			j++;
		}
		i++;
	}
					cub3d->player->dir->y = 0;
	return (cub3d);
}

int		raycasting(t_cub3d *cub3d)
{
	t_player	*player;
	// double		cam_x;
	double 		x;
	int			color;
	int			map_x;
	int			map_y;
	//temp given values
	cub3d->conf->res_w = 1920;
	cub3d->conf->res_h = 1080;
	int world_map[24][24] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	//end temp given values

	x = 0;
	cub3d = ft_set_pos(cub3d, world_map);
	player = cub3d->player;
	player->plane->x = 0;
	player->plane->y = 0.66;
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, cub3d->conf->res_w,
								cub3d->conf->res_h, "Cub3D");
	while( x < cub3d->conf->res_w)
	{
		player->cam->x = 2 * x / (double)cub3d->conf->res_w - 1;
		cub3d->ray->dir->x = player->dir->x +
											player->plane->x * player->cam->x;
		cub3d->ray->dir->y = player->dir->y +
											player->plane->y * player->cam->y;
		map_x = (int)player->pos->x;
		map_y = (int)player->pos->y;

		cub3d->ray->delta_dist->x = fabs(1/ cub3d->ray->dir->x);
		cub3d->ray->delta_dist->y = fabs(1/ cub3d->ray->dir->y);
		if (cub3d->ray->dir->x < 0)
		{
			player->step->x = -1;
			cub3d->ray->dist_x = (player->pos->x - map_x)
												* cub3d->ray->delta_dist->x;
		}
		else
		{
			player->step->x = 1;
			cub3d->ray->dist_x = (map_x + 1.0 - player->pos->x)
												* cub3d->ray->delta_dist->x;
		}
		if (cub3d->ray->dir->y < 0)
		{
			player->step->y = -1;
			cub3d->ray->dist_y = (player->pos->y - map_y)
												* cub3d->ray->delta_dist->y;
		}
		else
		{
			player->step->y = 1;
			cub3d->ray->dist_y = (map_y + 1.0 - player->pos->y)
												* cub3d->ray->delta_dist->y;
		}
		if(cub3d->ray->dist_x < cub3d->ray->dist_y)
		{
			cub3d->ray->dist_x += cub3d->ray->delta_dist->x;
			map_x += player->step->x;
			side = 0;
		}
		else
		{
			cub3d->ray->dist_y += cub3d->ray->delta_dist->y;
			mapY += player->step->y;
			side = 1;
		}
		if(worldMap[map_x][map_y] > 0) hit = 1;
		if(side == 0)
			cub3d->ray->perp_wall_dist = (map_x - player->pos->x +
							(1 - player->step->x) / 2) / cub3d->ray->dir->x;
		else
			cub3d->ray->perp_wall_dist = (map_y - player->pos->y +
										(1 - stepY) / 2) / rayDirY;


		if(world_map[(int)player->pos->x][(int)player->pos->y] == 1)
			color = 0xFF0000;
		else if (world_map[(int)player->pos->x][(int)player->pos->y] == 2)
			color = 0x008000;
		else if (world_map[(int)player->pos->x][(int)player->pos->y] == 3)
			color = 0x0000FF;
		else if (world_map[(int)player->pos->x][(int)player->pos->y] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;
	}
}
