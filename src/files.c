/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 17:07:51 by adorigo           #+#    #+#             */
/*   Updated: 2020/07/31 16:54:05 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			mouse_hook(int button, int x, int y, t_cub3d *cub3d)
{
	t_list_files	*list;

	list = cub3d->conf->list_files;
		printf("x :%d, y :%d\n", x, y);
	while (list->next != NULL)
	{
		if (( x >= list->x_init && x <= list->x_end) &&
			(y >= list->y_init && y <= list->y_end))
		{
			if (list->dirent->d_type == DT_REG)
			{
				printf("inside dt_reg if\n");
				if (!(cub3d->conf->file = ft_substr(list->dirent->d_name, 0,
					list->dirent->d_namlen)))
					return(err_free(-1, "file allocation failed\n", cub3d, 0));
				mlx_destroy_window(cub3d->mlx, cub3d->win);
				cub3d->exit = 1;
				return (0);
			}
			else if (list->dirent->d_type == DT_DIR)
			{
				printf("inside dt_dir if\n");
				free(cub3d->conf->mydir);
				if (!(cub3d->conf->mydir = ft_substr(list->dirent->d_name, 0,
					list->dirent->d_namlen)))
					return(err_free(-1, "file allocation failed", cub3d, 0));
			}
			else
			{
				exit(0);
			}
		}
		list = list->next;
	}
	cub3d->update = 0;
	return (1);
}

void		pos_x(t_cub3d *cub3d)
{
	t_list_files	*list;
	int				lst_len;
	int				i;
	int				j;

	cub3d->conf->pos->x = 640;
	i = 0;
	list = cub3d->conf->list_files;
	lst_len = ft_listsize(list);
	if ((lst_len / 15) == 0)
	{
		while (list->next != NULL)
		{
			if (cub3d->conf->d_name_len < list->dirent->d_namlen)
				cub3d->conf->d_name_len = list->dirent->d_namlen;
			list = list->next;
		}

		cub3d->conf->pos->x -= (cub3d->conf->d_name_len / 2 * 7);
	}
	else
	{
		i = lst_len / 15 + 1;
		while (i != 0)
		{
			j = 15;
			while (list->next != NULL && j != 0)
			{
				if (cub3d->conf->d_name_len < list->dirent->d_namlen)
					cub3d->conf->d_name_len = list->dirent->d_namlen;
				list = list->next;
				j--;
			}
			cub3d->conf->pos->x -= cub3d->conf->d_name_len / 2 * 7;
			i--;
		}
		if (cub3d->conf->pos->x < 30)
			cub3d->conf->pos->x = 30;
	}
}

/*
** the print_files() function will take the t_list_files structure
** and iterate through it, printing every element to the window.
** to do so the function will get the amount of files/directories, and save it
** in the lst_len variable, it will then loop lst_len times on the list.
** every time it loops on an element of the list, the function will save 
** an initial x (variable) and y (constant) position into that element's x_init
** and y_init variables, it then prints the dirent->name element to the window.
** after printing, it will take the new x and y positions, and save them into
** x_end and y_end, effectively creating a rectangular zone that can later be
** used to detect clicks or other stuff.
** I have decided that the max size for a column is 15 elements, so every
** 15 elements, the x_init and y_init position setters are reset to their
** original position (+ (the size * 7) of the biggest element in that list)
*/

int			print_files(t_cub3d *cub3d)
{
	t_list_files	*list;
	int				lst_len;
	int				i;

	cub3d->conf->pos->y = 120;
	pos_x(cub3d);
	printf("%f\n", 	cub3d->conf->pos->x); //debug
	i = 0;
	list = cub3d->conf->list_files;
	lst_len = ft_listsize(list);

	while (++i < lst_len)
	{
		list->x_init = (int)cub3d->conf->pos->x;
		list->y_init = (int)cub3d->conf->pos->y;
		mlx_string_put(cub3d->mlx, cub3d->win, cub3d->conf->pos->x,
			cub3d->conf->pos->y += 23, 0xFFFFFF, list->dirent->d_name);
		list->x_end = (cub3d->conf->pos->x + (cub3d->conf->d_name_len + 2) * 7);
		list->y_end = (int)cub3d->conf->pos->y;
		list = list->next;
		if (i%15 == 0)
		{
			cub3d->conf->pos->y = 120;
			cub3d->conf->pos->x += ((cub3d->conf->d_name_len + 2) * 7);
		}
	}
	return (1);
}

/*
** get_cub(t_cub3d *cub3d) is the function that will try and get the fd
** to the map file, in case it was not given as first argument when executing
** the program.
** what it does, is that it will get the current directory, and print it 
** to the window, it will then open the directory, and for every file in the
** directory, it will add them to the t_list_files *constructor variable. once
** it has read and saved all the files, it will call the print_files() function
*/

static int	get_cub(t_cub3d *cub3d)
{
	DIR				*dir;
	char			cwd[PATH_MAX];
	struct dirent	*dirent;
	t_list_files	*constructor;

	if (!(cub3d->conf->list_files = malloc(sizeof(dirent))))
		return (0);
	constructor = cub3d->conf->list_files;
	getcwd(cwd, sizeof(cwd));
	mlx_string_put(cub3d->mlx, cub3d->win, 405, 80, 0xFFFFFF,
		"please chose the directory in which you want to go, or the map file");
	mlx_string_put(cub3d->mlx, cub3d->win, 405, 100, 0xFFFFFF, cwd);
	dir = opendir(cub3d->conf->mydir);
	while ((dirent = readdir(dir)) != NULL)
	{
		constructor->dirent = dirent;
		if (!(constructor->next = malloc(sizeof(t_list_files))))
			return (0);
		constructor = constructor->next;
	}
	constructor->dirent = NULL;
	if (!(constructor->next = malloc(sizeof(t_list_files))))
		return (0);
	constructor->next = NULL;
	if (!print_files(cub3d))
		return (0);
	return (1);
}

/*
** second_loop(t_cub3d *cub3d) should really be called main_loop, but the name was already taken
** all this does is clear the window, clear the t_list_files struct
** and then go into the get_cub function
*/

int	second_loop(t_cub3d *cub3d)
{
	if (cub3d->update == 0)
	{
		printf("mydir : %s\n", cub3d->conf->mydir);
		mlx_clear_window(cub3d->mlx, cub3d->win);
		ft_listclear(cub3d);
		if (!(get_cub(cub3d)))
			return (err_msg(-1, "failed to get file\n", 0));
		cub3d->update = 1;
	}
	return (0);
}


/*
** run_mlx2(t_cub3d *cub3d) is the function that will loop over all the 
** mlx_hook types of function, and will allow for events to happen in the window previously generated
*/

int	run_mlx2(t_cub3d *cub3d)
{
	mlx_mouse_hook(cub3d->win, mouse_hook, cub3d);
	mlx_hook(cub3d->win, EVENT_KEY_PRESS, 0, keypress_callback, cub3d);
	mlx_hook(cub3d->win, EVENT_KEY_RELEASE, 0, keyrelease_callback, cub3d);
	mlx_hook(cub3d->win, EVENT_EXIT, 0, exit_callback, cub3d);
	mlx_loop_hook(cub3d->mlx, second_loop, cub3d);
	mlx_loop(cub3d->mlx);
	return (1);
}

/*
** get_file(t_cub3d *cub3d) is the function that initialises the mlx window and
** then goes into the run_mlx2() function
*/

int			get_file(t_cub3d *cub3d)
{
	
	if (!(cub3d->mlx = mlx_init()))
		return (err_msg(-1, "Failed to init mlx.\n", 0));
	if (!(cub3d->win = mlx_new_window(cub3d->mlx, 1280, 720, "cub3d")))
		return (err_msg(-1, "Failed to create cub3d->mlx window.\n", 0));
	if (!(cub3d->conf->mydir = ft_strdup(".")))
		return (0);
	run_mlx2(cub3d);
	return (1);
}
