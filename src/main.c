/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 14:44:33 by adorigo           #+#    #+#             */
/*   Updated: 2020/07/31 12:02:10 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** the main function of the cub3d project will check how many arguments were
** passed to the executable, and will execute the program differently according
** to how many arguments it got
*/

int	main(int ac, char **av)
{
	t_cub3d		cub3d;

	if (ac == 1)
	{
		if (!init_cub3d(&cub3d) || !get_file(&cub3d) || !set_cub3d(av[1], &cub3d)
			|| !set_screen(&cub3d) || !load_texture(&cub3d))
			exit(EXIT_FAILURE);
		run_mlx(&cub3d);
	}
	else if (ac == 2)
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
