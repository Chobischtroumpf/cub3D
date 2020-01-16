/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:49:58 by adorigo           #+#    #+#             */
/*   Updated: 2020/01/16 08:01:36 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	main(int ac, char **av)
{

	t_cub3d		cub3d;

	if(ac == 2)
	{
		if (!(cub_init(&cub3d)) || set_screen(&cub3d))
			return(EXIT_FAILURE);
		run_mlx(&cub3d);
	}
	else if (ac == 3 && !ft_strcmp(av[2], "-save"))
	{

	}
	else if (ac == 3 && ft_strcmp(av[2], "-save"))
		return(msg_err(-1, "wrong option.\n", EXIT_FAILURE));
	else if (ac > 3)
		return(msg_err(-1, "too many args.\n", EXIT_FAILURE));
	return(EXIT_SUCCESS);
}
