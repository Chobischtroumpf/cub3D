/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:19:13 by adorigo           #+#    #+#             */
/*   Updated: 2019/11/15 11:45:28 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(const char *s)
{
	ssize_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, ssize_t len)
{
	char	*ptr;
	char	*ret;
	char	*cpy_ret;

	if (!s || !(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start >= ft_strlen(s))
		ret[0] = '\0';
	else
	{
		ptr = (char*)s + start;
		cpy_ret = ret;
		while (*ptr != '\0' && len-- > 0)
			*cpy_ret++ = *ptr++;
		*cpy_ret = '\0';
	}
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t r_size)
{
	int		len;
	char	*res;
	ssize_t	i;

	len = ft_strlen(s1) + r_size;
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && *s2 != '\0')
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}
