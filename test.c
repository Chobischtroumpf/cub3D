/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 14:33:13 by adorigo           #+#    #+#             */
/*   Updated: 2020/02/10 14:33:52 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			check_grid(t_cub3d *cub3d)
{
	int		w;
	int		h;
	int		i;
	char	**grid;

	w = cub3d->conf->grid_w;
	h = cub3d->conf->grid_h;
	grid = cub3d->grid;
	if (!check_grid_line(grid[0], w, 'f', cub3d)
		|| !check_grid_line(grid[h - 1], w, 'l', cub3d))
		return (0);
	i = 0;
	while (++i < h - 1)
		if (!check_grid_line(grid[i], w, 'm', cub3d))
			return (0);
	if (cub3d->player->pos->x == 0 && cub3d->player->pos->y == 0)
		return (err_free(-1,
					"Wrong map description : no player position.\n", cub3d, 0));
	return (1);
}
