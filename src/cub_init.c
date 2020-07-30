/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 07:26:52 by adorigo           #+#    #+#             */
/*   Updated: 2020/07/29 14:46:04 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_player *p)
{
	position_setter(p->pos, 0.0, 0.0);
	p->rot_speed = 3;
	p->mov_dir = 0;
	p->rot_dir = 0;
	p->hor_mov = 0;
	p->hor_mov = 0;
}

static void	init_conf(t_config *conf, t_tex *tex)
{
	int i;

	i = -1;
	while (++i < 5)
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
	conf->d_name_len = 0;
	conf->list_files = NULL;

}

static void	init_cub(t_cub3d *cub)
{
	cub->grid = 0;
	cub->mlx = 0;
	cub->win = 0;
	cub->img = 0;
	cub->data = 0;
	cub->zbuff = 0;
	cub->sp = 0;
	cub->parsing = 0;
	cub->update = 0;
	cub->exit = 0;
}

int			init_cub3d(t_cub3d *cub)
{
	if (!(cub->conf = malloc(sizeof(t_config)))
		|| !(cub->conf->tex = malloc(sizeof(t_tex)))
		|| !(cub->conf->list_files = malloc(sizeof(t_list_files)))
		|| !(cub->conf->pos = malloc(sizeof(t_pos)))
		|| !(cub->player = malloc(sizeof(t_player)))
		|| !(cub->player->pos = malloc(sizeof(t_pos)))
		|| !(cub->player->dir = malloc(sizeof(t_pos)))
		|| !(cub->player->plane = malloc(sizeof(t_pos)))
		|| !(cub->ray = malloc(sizeof(t_ray)))
		|| !(cub->ray->dir = malloc(sizeof(t_pos))))
		return (err_free(-1, "Initialisation failed.\n", cub, 0));
	init_conf(cub->conf, cub->conf->tex);
	init_player(cub->player);
	init_cub(cub);
	return (1);
}
