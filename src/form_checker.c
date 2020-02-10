/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:35:11 by wpark             #+#    #+#             */
/*   Updated: 2020/02/10 16:25:19 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	grid_form_checker(char *form)
{
	int grid_w;

	grid_w = 0;
	while (*form != '\0')
	{
		if (*form != '0' && *form != '1' && *form != '2' && *form != ' ' 
			&& *form != '\t' && *form!= '\v' && *form != '\f' && *form != '\r'
			&& *form != 'N' && *form != 'S' && *form != 'E' && *form != 'W')
			return (0);
		if ((ft_isdigit(*form) || *form == 'N'
			|| *form == 'S' || *form == 'E' || *form == 'W'))
			grid_w++;
		form++;
	}
	return (grid_w);
}

int	check_color_form(char *form)
{
	int	nb_num;
	int	ck;
	int res;

	res = 0;
	ck = 0;
	nb_num = 0;
	while (*form != '\0')
	{
		if (!ft_isdigit(*form) && *form != ' ' && *form != ',')
			return (0);
		if (ck == 0 && ft_isdigit(*form) && (ck = 1) && ++nb_num)
			res++;
		else if (ck == 1 && *form == ' ')
			ck = 0;
		else if (*form == ',' && !(ck = 0))
			res--;
		if (res != 1 && res != 0)
			return (0);
		form++;
	}
	if (nb_num != 3)
		return (0);
	return (1);
}

int	resolution_form_checker(char *form)
{
	int	ck;
	int	nb_num;

	ck = 0;
	nb_num = 0;
	while (*form != '\0')
	{
		if (!ft_isdigit(*form) && *form != ' ')
			return (0);
		if (ck == 1 && *form == ' ')
			ck = 0;
		if (ck == 0 && ft_isdigit(*form) && (ck = 1))
		{
			if (++nb_num > 2)
				return (0);
		}
		form++;
	}
	if (nb_num != 2)
		return (0);
	return (1);
}

int	is_wall(int new_x, int new_y, t_cub3d *cub3d)
{
	if (new_x > cub3d->conf->grid_w - 1 || new_y > cub3d->conf->grid_h - 1)
		return (1);
	if (cub3d->grid[new_y][new_x] == 1)
		return (1);
	if (cub3d->grid[new_y][new_x] == 2)
		return (2);
	return (0);
}

int	is_nsew(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
