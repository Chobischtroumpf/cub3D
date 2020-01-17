/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:34:34 by adorigo           #+#    #+#             */
/*   Updated: 2020/01/17 17:59:19 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// 
//	 C'EST UN PROBLEME DE CAST
// 	 FAUT DECLARER LE X EN DOUBLE ET CHECK LES AUTRES CASTS
//

#include "../cub3d.h"

/* t_cub3d	*ft_set_pos(t_cub3d *cub3d, int world_map[24][24])
** {
** 	int i;
** 	int j;

** 	while (world_map[i++])
** 	{
** 		j = 0;
** 		while(world_map[i][j])
** 		{
** 			if (world_map[i][j] == 6)
** 			{
** 				cub3d->player->pos->x = i;
** 				cub3d->player->pos->y = j;
** 				cub3d->player->dir->x = -1;
** 				return (cub3d);
** 			}
** 			j++;
** 		}
** 	}
** 	cub3d->player->dir->y = 0;
** 	return (cub3d);
** }
*/

int verLine(void *mlx_ptr, void *win_ptr, int x, int drawStart, int drawEnd, int color)
{
	while (drawStart < drawEnd)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, drawStart, color);
		drawStart++;
	}
	return(1);
}

int		raycasting(t_cub3d *cub3d)
{
	t_player	*p;
	double 		x;
	int			color;
	int			map_x;
	int			map_y;

	//temp given values
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
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
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

	x = 1;
	p = cub3d->player;
	p->pos->x = 21;
	p->pos->y = 12;
	p->dir->x = -1;
	p->dir->y = 0;
	p->plane->x = 0;
	p->plane->y = 0.66;
	color = 0x0;
	// while(x++ < cub3d->conf->res_w)
	// 	verLine(cub3d->mlx, cub3d->win, x, 0, 1920, color);
	while (x < cub3d->conf->res_w)
	{
		p->cam->x = (double)(2 * x / cub3d->conf->res_w - 1);
		printf("valeur de x : %f\nposition camera x : %f\n",x ,p->cam->x);
		cub3d->ray->dir->x = p->dir->x + p->plane->x * p->cam->x;
		cub3d->ray->dir->y = p->dir->y + p->plane->y * p->cam->x;
		map_x = (int)p->pos->x;
		map_y = (int)p->pos->y;
		printf("direction plan x : %f\n direction plan y : %f\ndirection rayon x : %f\n direction rayon y : %f\n position x : %f\n position y : %f\n",p->plane->x ,p->plane->y ,cub3d->ray->dir->x, cub3d->ray->dir->y, p->pos->x, p->pos->y);
		cub3d->ray->delta_dist->x = fabs(1 / cub3d->ray->dir->x);
		cub3d->ray->delta_dist->y = fabs(1 / cub3d->ray->dir->y);
		printf("distance delta du rayon x : %f\n distance delta du rayon y : %f\n", cub3d->ray->delta_dist->x, cub3d->ray->delta_dist->y);
		if (cub3d->ray->dir->x < 0)
		{
			p->step->x = -1;
			cub3d->ray->dist_x = (p->pos->x - map_x) *
												cub3d->ray->delta_dist->x;
			printf(" distance rayon x : %f\n", cub3d->ray->dist_x);
		}
		else
		{
			p->step->x = 1;
			cub3d->ray->dist_x = (map_x + 1.0 - p->pos->x)
												* cub3d->ray->delta_dist->x;
			printf(" distance rayon x : %f\n", cub3d->ray->dist_x);
		}
		if (cub3d->ray->dir->y < 0)
		{
			p->step->y = -1;
			cub3d->ray->dist_y = (p->pos->y - map_y)
												* cub3d->ray->delta_dist->y;
			printf(" distance rayon y : %f\n", cub3d->ray->dist_y);
		}
		else
		{
			p->step->y = 1;
			cub3d->ray->dist_y = (map_y + 1.0 - p->pos->y)
												* cub3d->ray->delta_dist->y;
			printf(" distance rayon y : %f\n", cub3d->ray->dist_y);
		}
		if (cub3d->ray->dist_x < cub3d->ray->dist_y)
		{
			cub3d->ray->dist_x += cub3d->ray->delta_dist->x;
			map_x += p->step->x;
			cub3d->ray->side = 0;
			printf(" distance rayon x if smaller than y : %f\n", cub3d->ray->dist_x);
		}
		else
		{
			cub3d->ray->dist_y += cub3d->ray->delta_dist->y;
			map_y += p->step->y;
			cub3d->ray->side = 1;
			printf(" distance rayon y if x is bigger than y : %f\n", cub3d->ray->dist_y);
		}
		if (world_map[map_x][map_y] > 0)
			cub3d->ray->w_hit = 1;
		if (cub3d->ray->side == 0)
		{
			cub3d->ray->perp_wdist = fabs((map_x - p->pos->x +
							(1 - p->step->x) / 2) / cub3d->ray->dir->x); //added fabs might need removal
			printf(" distance mur perpendiculaire : %f\n", cub3d->ray->perp_wdist);
		}
		else
		{
			cub3d->ray->perp_wdist = fabs((map_y - p->pos->y + (1 - p->step->y) / 2)
														/ cub3d->ray->dir->y); // added fabs might need removal later
			// printf(" distance mur perpendiculaire else : %f\n");
		}
		cub3d->ray->w_height = (cub3d->conf->res_h / cub3d->ray->perp_wdist);
		// printf("%d", cub3d->ray->w_height);

		cub3d->ray->draw_start = -cub3d->ray->w_height / 2
													+ cub3d->conf->res_h / 2;

		if (cub3d->ray->draw_start < 0)
			cub3d->ray->draw_start = 0;
		cub3d->ray->draw_end = -cub3d->ray->w_height / 2
													+ cub3d->conf->res_h / 2;
		if (cub3d->ray->draw_end >= cub3d->conf->res_h)
			cub3d->ray->draw_end = cub3d->conf->res_h;

		// if (world_map[(int)p->pos->x][(int)p->pos->y] == 1)
		// 	color = 0xFF0000;
		// else if (world_map[(int)p->pos->x][(int)p->pos->y] == 2)	
		// 	color = 0x008000;
		// else if (world_map[(int)p->pos->x][(int)p->pos->y] == 3)
		// 	color = 0x0000FF;
		// else if (world_map[(int)p->pos->x][(int)p->pos->y] == 4)
		// 	color = 0xFFFFF0;
		// else
		// 	color = 0xFFFF00;
		
		switch(world_map[map_x][map_y])
		{
        case 1:  color = 0xFFFF00;    break; //red
        case 2:  color = 0x008000;  break; //green
        case 3:  color = 0x0000FF;   break; //blue
        case 4:  color = 0xFFFFFF;  break; //white
        default: color = 0xFF0000; break; //yellow
		}
	    if (cub3d->ray->side == 1)
			color = color / 2;
		printf("%d\n,%d\n, %x\n", cub3d->ray->draw_start, cub3d->ray->draw_end, color);
		verLine(cub3d->mlx, cub3d->win, x, cub3d->ray->draw_start,
												cub3d->ray->draw_end, color);
		x++;
	}
	cub3d->player = p;
	return(0);
}

