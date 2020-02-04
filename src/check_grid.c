/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 09:08:07 by adorigo           #+#    #+#             */
/*   Updated: 2020/02/04 07:46:51 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player(char dir, int w, int h, t_cub3d *cub3d)
{
	position_setter(cub3d->player->pos, w + 0.5, h + 0.5);
	if (dir == 'N')
	{
		position_setter(cub3d->player->dir, -1, 0);
		position_setter(cub3d->player->plane, 0, -0.66);
	}
	else if (dir == 'S')
	{
		position_setter(cub3d->player->dir, 1, 0);
		position_setter(cub3d->player->plane, 0, 0.66);
	}
	else if (dir == 'E')
	{
		position_setter(cub3d->player->dir, 0, 1);
		position_setter(cub3d->player->plane, -0.66, 0);
	}
	else if (dir == 'W')
	{
		position_setter(cub3d->player->dir, 0, -1);
		position_setter(cub3d->player->plane, 0.66, 0);
	}
}

static int	middle_grid_checker(char *line, int w, t_cub3d *cub3d, int h)
{
	int i;

	i = -1;
	while (++i < w)
	{
		if (is_nsew(line[i]) && cub3d->player->pos->x != 0
			&& cub3d->player->pos->y != 0)
			return (err_free(-1,
					"Invalid player position.\n", cub3d, 0));
		else if (is_nsew(line[i]) && cub3d->player->pos->x == 0
				&& cub3d->player->pos->y == 0)
			set_player(line[i], i, h, cub3d);
		else if (line[i] == 2)
			sp_add_back(&cub3d->sp, i, h);
	}
	return (1);
}

static int	grid_line_checker(char *line, int w, char op, t_cub3d *cub3d)
{
	int			i;
	static int	h = -1;

	i = -1;
	if ((op == 'f' || op == 'l') && ++h >= 0)
	{
		while (++i < w)
		{
			if (line[i] != 1)
				return (err_free(-1,
						"Map is not surrounded by wall\n", cub3d, 0));
		}
	}
	else if (op == 'm')
	{
		if (line[0] != 1 || line[w - 1] != 1)
		{
			return (err_free(-1,
					"Map is not surrounded by wall\n", cub3d, 0));
		}
		if (!(middle_grid_checker(line, w, cub3d, h)))
			return (0);
		h++;
	}
	return (1);
}

int			check_grid(t_cub3d *cub3d)
{
	int		w;
	int		h;
	int		i;
	char	**grid;

	w = cub3d->conf->grid_w;
	h = cub3d->conf->grid_h;
	grid = cub3d->grid;
	if (!grid_line_checker(grid[0], w, 'f', cub3d)
		|| !grid_line_checker(grid[h - 1], w, 'l', cub3d))
		return (0);
	i = 0;
	while (++i < h - 1)
	{
		if (!grid_line_checker(grid[i], w, 'm', cub3d))
			return (0);
	}
	if (cub3d->player->pos->x == 0 && cub3d->player->pos->y == 0)
	{
		return (err_free(-1,
				"Wrong map description : no player position.\n", cub3d, 0));
	}
	return (1);
}
