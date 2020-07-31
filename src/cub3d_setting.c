/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:08:36 by adorigo           #+#    #+#             */
/*   Updated: 2020/07/31 14:21:08 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*
** ck_extention(char *map_file, t_cub3d *cub3d) takes the map_file variable and
** in the event it is not ".cub", frees the t_cub3d structure and returns -1
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

/*
** ck_config(t_cub3d *cub3d) takes the t_cub3d struct, and checks that all the
** necessary informations were correctly saved in the structure, in case they
** were not, it will free the structure, print the appropriate message and
** return -1
*/

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

/*
** set_cub3d(char *map_file, t_cub3d *cub3d) takes the name of the file with
** the map and all necessary info, and will check that the file is correct
** and save all of it's data internally
*/

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
		if (*line == '\0' && cub3d->parsing != 1)
			continue;
		else if (!line)
			return (0);
		else if (!get_config(line, cub3d))
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
