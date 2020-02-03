/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 06:55:44 by adorigo           #+#    #+#             */
/*   Updated: 2020/02/03 06:54:08 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	position_setter(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

void	rotate_pos(t_pos *pos, double rad)
{
	double	rot_x;
	double	rot_y;

	rot_x = cos(rad) * pos->x - sin(rad) * pos->y;
	rot_y = sin(rad) * pos->x + cos(rad) * pos->y;
	position_setter(pos, rot_x, rot_y);
}

int		move_player_fb(t_cub3d *cub)
{
	t_player	*p;

	p = cub->player;
	if (p->mov_dir == 2)
	{
		if(cub->grid[(int)(p->pos->x + p->dir->x * MS + ((p->dir->x < 0) ? -0.2 : 0.2))][(int)(p->pos->y)] != 1)
			p->pos->x += p->dir->x * MS;
		if(cub->grid[(int)(p->pos->x)][(int)(p->pos->y + p->dir->y * MS - ((p->dir->y < 0) ? 0.2 : -0.2))] != 1)
			p->pos->y += p->dir->y * MS;
	}
	else if (p->mov_dir == 1)
	{
		if(cub->grid[(int)(p->pos->x - p->dir->x * MS + ((p->dir->x < 0) ? 0.2 : -0.2))][(int)(p->pos->y)]!= 1)
			p->pos->x -= p->dir->x * MS;
		if(cub->grid[(int)(p->pos->x)][(int)(p->pos->y + p->dir->y * MS - ((p->dir->y < 0) ? -0.4 : 0.4))] != 1)
			p->pos->y -= p->dir->y * MS;
	}
	
	return (1);
}

int		rotate_player(t_cub3d *cub3d)
{
	t_player	*p;
	double		rot_rad;

	p = cub3d->player;
	rot_rad = deg2rad(p->rot_dir * p->rot_speed);
	rotate_pos(cub3d->player->dir, rot_rad);
	rotate_pos(cub3d->player->plane, rot_rad);
	return (1);
}

int		move_player_rl(t_cub3d *cub)
{
	t_player	*p;

	p = cub->player;
	if (p->mov_dir == -1)
	{
		if(cub->grid[(int)(p->pos->x + p->dir->y * MS + ((p->dir->y < 0) ? -0.2 : 0.2))][(int)(p->pos->y)]!= 1)
			p->pos->x += p->dir->y * MS;
		if(cub->grid[(int)(p->pos->x)][(int)(p->pos->y - p->dir->x * MS - ((p->dir->x < 0) ? -0.2 : 0.2))] != 1)
			p->pos->y -= p->dir->x * MS;
	}
	else if (p->mov_dir == -2)
	{
		if(cub->grid[(int)(p->pos->x - p->dir->y * MS - ((p->dir->y < 0) ? -0.2 : 0.2))][(int)(p->pos->y)] != 1)
			p->pos->x -= p->dir->y * MS;
		if(cub->grid[(int)(p->pos->x)][(int)(p->pos->y + p->dir->x * MS + ((p->dir->x < 0) ? 0.2 : -0.2))] != 1)
			p->pos->y += p->dir->x * MS;
	}
	return (1);
}
