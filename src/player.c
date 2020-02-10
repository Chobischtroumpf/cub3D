/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 06:55:44 by adorigo           #+#    #+#             */
/*   Updated: 2020/02/10 11:44:52 by adorigo          ###   ########.fr       */
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

int		move_player_fb(t_cub3d *cub3d)
{
	double		new_x;
	double		new_y;
	t_player	*p;

	p = cub3d->player;
	new_x = p->pos->x + p->dir->x * MS * p->mov_dir;
	new_y = p->pos->y + p->dir->y * MS * p->mov_dir;
	if (!(is_wall((int)new_x, (int)new_y, cub3d)))
		position_setter(p->pos, new_x, new_y);
	return (1);
}

int		move_player_rl(t_cub3d *cub3d)
{
	double		new_x;
	double		new_y;
	t_player	*p;

	p = cub3d->player;
	if (p->hor_mov > 0)
	{
		new_x = p->pos->x - p->dir->y * MS;
		new_y = p->pos->y + p->dir->x * MS;
	}
	if (p->hor_mov < 0)
	{
		new_x = p->pos->x + p->dir->y * MS;
		new_y = p->pos->y - p->dir->x * MS;
	}
	if (!(is_wall((int)new_x, (int)new_y, cub3d)))
		position_setter(p->pos, new_x, new_y);
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
