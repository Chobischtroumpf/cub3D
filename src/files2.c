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

static void	ft_listdelone(t_list_files *lst)
{
	if (lst)
	{
		free(lst);
		lst = 0;
	}
}

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
