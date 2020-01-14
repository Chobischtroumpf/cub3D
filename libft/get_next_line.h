/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:51:48 by adorigo           #+#    #+#             */
/*   Updated: 2019/11/19 13:47:13 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int				get_next_line(int fd, char **line);
ssize_t			ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2, ssize_t r_size);
char			*ft_substr(char const *s, unsigned int start, ssize_t len);

#endif
