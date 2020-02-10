/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:44:33 by adorigo           #+#    #+#             */
/*   Updated: 2020/02/10 16:29:26 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d		cub3d;

	if (ac == 2)
	{
		if (!init_cub3d(&cub3d) || !set_cub3d(av[1], &cub3d)
			|| !set_screen(&cub3d) || !load_texture(&cub3d))
			exit(EXIT_FAILURE);
		run_mlx(&cub3d);
	}
	else if (ac == 3 && !ft_strcmp(av[2], "--save"))
	{
		if (!init_cub3d(&cub3d) || !set_cub3d(av[1], &cub3d)
			|| !set_screen(&cub3d) || !load_texture(&cub3d))
			exit(EXIT_FAILURE);
		screen_shot(&cub3d);
	}
	else if (ac == 3 && ft_strcmp(av[2], "--save"))
		return (err_msg(-1, "Wrong option.\n", EXIT_FAILURE));
	else if (ac > 3)
		return (err_msg(-1, "Too many arguments.\n", EXIT_FAILURE));
	exit(0);
}
