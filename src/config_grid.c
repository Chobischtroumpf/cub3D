/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 07:19:07 by adorigo           #+#    #+#             */
/*   Updated: 2020/02/10 16:54:47 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	make_grid_line(char *line, char *new_line, int w)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (i != w)
	{
		line = ft_strtrim(line, " \n\t\v\f\r");
		if (ft_isdigit(*line))
			nb = nb * 10 + *line - '0';
		else if (is_nsew(*line))
			nb = (int)*line;
		new_line[i++] = nb;
		nb = 0;
		line++;
	}
}

char		**join_grid(char **grid, char *line, t_cub3d *cub3d)
{
	char	**new_grid;
	char	*new_line;
	int		i;

	cub3d->parsing = 1;
	if (!(new_grid = (char**)malloc(sizeof(char*) * cub3d->conf->grid_h)))
	{
		cub3d->conf->grid_h -= 1;
		return (0);
	}
	if (!(new_line = (char*)malloc(sizeof(char) * (cub3d->conf->grid_w + 1))))
	{
		cub3d->conf->grid_h -= 1;
		return (0);
	}
	make_grid_line(line, new_line, cub3d->conf->grid_w);
	i = -1;
	while (++i < cub3d->conf->grid_h - 1)
		new_grid[i] = grid[i];
	new_line[cub3d->conf->grid_w] = '\0';
	new_grid[i] = new_line;
	return (new_grid);
}
