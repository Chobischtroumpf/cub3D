/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 23:57:41 by adorigo           #+#    #+#             */
/*   Updated: 2020/04/23 13:59:08 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*
** ft_listsize(t_list_files *lst) will take a t_list_files structure
** and count how many elements it has and returns the retrieved value
*/
int			ft_listsize(t_list_files *lst)
{
	int cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

/*
** ft_listdelone(t_list_files *lst) ft_listdelone takes the current element in
** *lst and frees it, it does not return anything
*/
static void	ft_listdelone(t_list_files *lst)
{
	if (lst)
	{
		free(lst);
		lst = 0;
	}
}

/*
** ft_listclear(t_cub3d *cub) takes the t_cub3d structure, and deletes every
** element in the t_list_files sub-structure
*/

void		ft_listclear(t_cub3d *cub)
{
	t_list_files *list;
	t_list_files *nxt;

	if (cub->conf->list_files != NULL)
	{
		list = cub->conf->list_files;
		while (list)
		{
			nxt = list->next;
			ft_listdelone(list);
			list = nxt;
		}
		list = NULL;
	}
}
