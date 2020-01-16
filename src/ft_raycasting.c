/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:34:34 by adorigo           #+#    #+#             */
/*   Updated: 2020/01/16 07:32:11 by adorigo          ###   ########.fr       */
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
	t_player	*p;
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
	p = cub3d->player;
	p->plane->x = 0;
	p->plane->y = 0.66;
	cub3d->mlx = mlx_init();
	cub3d->win = mlx_new_window(cub3d->mlx, cub3d->conf->res_w,
								cub3d->conf->res_h, "Cub3D");
	while( x < cub3d->conf->res_w)
	{
		p->cam->x = 2 * x / (double)cub3d->conf->res_w - 1;
		cub3d->ray->dir->x = p->dir->x +
											p->plane->x * p->cam->x;
		cub3d->ray->dir->y = p->dir->y +
											p->plane->y * p->cam->y;
		map_x = (int)p->pos->x;
		map_y = (int)p->pos->y;

		cub3d->ray->delta_dist->x = fabs(1/ cub3d->ray->dir->x);
		cub3d->ray->delta_dist->y = fabs(1/ cub3d->ray->dir->y);
		if (cub3d->ray->dir->x < 0)
		{
			p->step->x = -1;
			cub3d->ray->dist_x = (p->pos->x - map_x)
			* cub3d->ray->delta_dist->x;
		}
		else
		{
			p->step->x = 1;
			cub3d->ray->dist_x = (map_x + 1.0 - p->pos->x)
												* cub3d->ray->delta_dist->x;
		}
		if (cub3d->ray->dir->y < 0)
		{
			p->step->y = -1;
			cub3d->ray->dist_y = (p->pos->y - map_y)
												* cub3d->ray->delta_dist->y;
		}
		else
		{
			p->step->y = 1;
			cub3d->ray->dist_y = (map_y + 1.0 - p->pos->y)
												* cub3d->ray->delta_dist->y;
		}
		if (cub3d->ray->dist_x < cub3d->ray->dist_y)
		{
			cub3d->ray->dist_x += cub3d->ray->delta_dist->x;
			map_x += p->step->x;
			cub3d->ray->side = 0;
		}
		else
		{
			cub3d->ray->dist_y += cub3d->ray->delta_dist->y;
			map_y += p->step->y;
			cub3d->ray->side = 1;
		}
		if (world_map[map_x][map_y] > 0)
			cub3d->ray->wall_hit = 1;
		if (cub3d->ray->side == 0)
			cub3d->ray->perp_wall_dist = (map_x - p->pos->x +
							(1 - p->step->x) / 2) / cub3d->ray->dir->x;
		else
			cub3d->ray->perp_wall_dist = (map_y - p->pos->y +
										(1 - cub3d->p->step->y) / 2)
										/ cub3d->ray->dir->y;
		cub3d->ray->wall_height = (int)(cub3d->conf->res_h
											/ cub3d->ray->perp_wall_dist);
		cub3d->ray->draw_start = -cub3d->ray->wall_height / 2
												+ cub3d->conf->res_h / 2;
		if (cub3d->ray->draw_start < 0)
			cub3d->ray->draw_start = 0;
		cub3d->ray->draw_end = -cub3d->ray->wall_height / 2
												+ cub3d->conf->res_h / 2;

		if (cub3d->ray->draw_end >= cub3d->conf->res_h)
			cub3d->ray->draw_end = cub3d->conf->res_h;

		if(world_map[(int)p->pos->x][(int)p->pos->y] == 1)
			color = 0xFF0000;
		else if (world_map[(int)p->pos->x][(int)p->pos->y] == 2)
			color = 0x008000;
		else if (world_map[(int)p->pos->x][(int)p->pos->y] == 3)
			color = 0x0000FF;
		else if (world_map[(int)p->pos->x][(int)p->pos->y] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;
	}
}
