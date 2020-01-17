/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:26:04 by adorigo           #+#    #+#             */
/*   Updated: 2020/01/17 17:45:49 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

static int	keypress_callback(int keycode, t_cub3d *cub3d)
{
	t_player	*p;

	p = cub3d->player;
	if (keycode == KEY_UP || keycode == KEY_W)
		p->mov_dir = 1;
	if (keycode == KEY_DOWN || keycode == KEY_S)
		p->mov_dir = -1;
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		p->rot_dir = 1;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		p->rot_dir = -1;
	return (0);
}

static int	keyrelease_callback(int keycode, t_cub3d *cub3d)
{
	t_player	*p;

	p = cub3d->player;
	if (keycode == KEY_UP || keycode == KEY_W)
		p->mov_dir = 0;
	if (keycode == KEY_DOWN || keycode == KEY_S)
		p->mov_dir = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		p->rot_dir = 0;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		p->rot_dir = 0;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(cub3d->mlx, cub3d->win);
		exit(0);
	}
	return (0);
}

static int	exit_callback(t_cub3d *cub3d)
{
	free_all(cub3d, 1);
	exit(EXIT_SUCCESS);
	return (1);
}

static int	main_loop(t_cub3d *cub3d)
{
	static int	update = 1;
	t_player	*p;

	if (update)
	{
		ft_putstr("avant raycasting\n");
		raycasting(cub3d);
	// 	render(cub3d);
		update = 0;
	}
	p = cub3d->player;
	// if (!p->rot_dir && !p->mov_dir)
	// 	update = 0;
	// if (p->rot_dir)
	// 	update = rotate_player(cub3d);
	// if (p->mov_dir)
	// 	update = move_player(cub3d);
	return (0);
}

int			run_mlx(t_cub3d *cub3d)
{
	ft_putstr_fd("avant mlx_hook\n",1);
	// mlx_hook(cub3d->win, EVENT_KEY_PRESS, 0, keypress_callback, cub3d);
	// ft_putstr_fd("avant mlx_hook 2\n",1);
	// mlx_hook(cub3d->win, EVENT_KEY_RELEASE, 0, keyrelease_callback, cub3d);
	// ft_putstr_fd("avant mlx_hook 3\n",1);
	// mlx_hook(cub3d->win, EVENT_EXIT, 0, exit_callback, cub3d);
	// ft_putstr_fd("avant mlx_loop_hook\n",1);
	mlx_loop_hook(cub3d->mlx, main_loop, cub3d);
	mlx_loop(cub3d->mlx);
	return (1);
}
