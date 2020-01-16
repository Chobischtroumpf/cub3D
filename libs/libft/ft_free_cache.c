/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cache.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:20:47 by adorigo           #+#    #+#             */
/*   Updated: 2019/12/05 14:18:36 by alessandro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		free_cache(char **cache, int ret)
{
	if (*cache)
	{
		free(*cache);
		*cache = 0;
	}
	return (ret);
}
