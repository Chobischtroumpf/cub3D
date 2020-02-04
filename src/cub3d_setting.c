/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:08:36 by adorigo           #+#    #+#             */
/*   Updated: 2020/02/04 14:17:03 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** check if map is surounded by 1
** check if there is only one "N/S/E/W"
** check if there is charactor except from 0, 1, 2, NSEW
*/

static int	ck_extention(char *map_file, t_cub3d *cub3d)
{
	if (!ft_strlast(map_file, ".cub"))
	{
		return (err_free(-1,
			"Invalid map file. Please check file extention (.cub)\n",
			cub3d, 0));
	}
	return (1);
}

static int	ck_config(t_cub3d *cub3d)
{
	t_config	*conf;

	conf = cub3d->conf;
	if (conf->res_w <= 0 || conf->res_h <= 0)
		return (err_free(-1, "Invalid resolution number.\n", cub3d, 0));
	if (conf->res_w < RMIN_W || conf->res_h < RMIN_H)
	{
		conf->res_w = RMIN_W;
		conf->res_h = RMIN_H;
	}
	if (conf->color_c < 0)
		return (err_free(-1, "Ceiling color not defined.\n", cub3d, 0));
	if (conf->color_f < 0)
		return (err_free(-1, "Floor color not defined.\n", cub3d, 0));
	if (!(cub3d->zbuff = malloc(sizeof(double) * conf->res_w)))
		return (err_free(-1, "Failed to malloc zbuff.\n", cub3d, 0));
	if (!check_grid(cub3d))
		return (0);
	return (1);
}

int			set_cub3d(char *map_file, t_cub3d *cub3d)
{
	char	*line;
	int		fd;

	if (!ck_extention(map_file, cub3d))
		return (0);
	if ((fd = open(map_file, O_RDONLY)) < 0)
		return (err_free(errno, 0, cub3d, 0));
	line = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!line)
			return(0);
		else if (!line_parsing(line, cub3d))
		{
			ft_strfree(&line, 0);
			return (0);
		}
		ft_strfree(&line, 0);
	}
	ft_strfree(&line, 0);
	close(fd);
	return (ck_config(cub3d));
}
