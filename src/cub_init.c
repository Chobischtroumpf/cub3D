/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:13:01 by adorigo           #+#    #+#             */
/*   Updated: 2020/01/17 14:45:17 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void init_ray(t_ray *ray)
{
	ray->dist_x = 0.0;
	ray->dist_y = 0.0;
	ray->delta_dist->x = 0;
	ray->delta_dist->y = 0;
	ray->perp_wdist = 0.0;
	ray->w_hit = 0;
	ray->w_height = 0;
	ray->w_type = 0;
	ray->side = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

static void init_player(t_player *p)
{
	p->pos->x = 0.0;
	p->pos->y = 0.0;
	p->mov_speed = 0.15;
	p->rot_speed = 1;
	p->rot_dir = 0;
	p->mov_dir = 0;
	p->step->x = 0;
	p->step->y = 0;
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
	conf->res_w = 1920;
	conf->res_h = 1080;
	conf->color_c = 0;
	conf->color_f = 0;
}

static void	init_cub(t_cub3d *cub)
{
	// cub->grid = 0;
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
		|| !(cub->player->cam = malloc(sizeof(t_pos)))
		|| !(cub->player->step = malloc(sizeof(t_pos)))
		|| !(cub->ray = malloc(sizeof(t_ray)))
		|| !(cub->ray->dir = malloc(sizeof(t_pos)))
		|| !(cub->ray->delta_dist = malloc(sizeof(t_pos))))
		return (err_free(-1, "Initialisation failed.\n", cub, 0));
	init_ray(cub->ray);
	init_conf(cub->conf,cub->conf->tex);
	init_player(cub->player);
	init_cub(cub);
	return(1);
}
