/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:13:01 by adorigo           #+#    #+#             */
/*   Updated: 2020/01/16 07:24:04 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_player(t_player *p)
{
	p->pos->x = 0.0;
	p->pos->y = 0.0;
	p->mov_speed = 0.15;
	p->rot_speed = 1;
	p->rot_dir = 0;
	p->mov_dir = 0;
}

static void	init_conf(t_config *conf, t_tex *tex)
{
	int	i;

	i = -1;
	while(++i < 5)
	{
		tex->path[i] = 0;
		tex->img[i] = 0;
		tex->data[i] = 0;
	}
	conf->grid_w = 0;
	conf->grid_h = 0;
	conf->res_h = 0;
	conf->res_w = 0;
	conf->color_c = -1;
	conf->color_f = -1;
}

static void	init_cub(t_cub3d *cub)
{
	cub->grid = 0;
	cub->mlx = 0;
	cub->win = 0;
	cub->img = 0;
	cub->data = 0;
	// cub->zbuff = 0;
	cub->sp = 0;
}

int			cub_init(t_cub3d *cub)
{
	if (!(cub->conf = malloc(sizeof(t_config)))
		|| !(cub->conf->tex = malloc(sizeof(t_tex)))
		|| !(cub->player = malloc(sizeof(t_player)))
		|| !(cub->player->pos = malloc(sizeof(t_pos)))
		|| !(cub->player->dir = malloc(sizeof(t_pos)))
		|| !(cub->player->plane = malloc(sizeof(t_pos)))
		|| !(cub->ray = malloc(sizeof(t_ray)))
		|| !(cub->ray->dir = malloc(sizeof(t_pos))))
		return (err_free(-1, "Initialisation failed.\n", cub, 0));
	init_conf(cub->conf,cub->conf->tex);
	init_player(cub->player);
	init_cub
}
