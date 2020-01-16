# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alessandro <alessandro@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 11:53:12 by adorigo           #+#    #+#              #
#    Updated: 2019/12/05 17:15:07 by alessandro       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -I. -c
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c		\
		ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c	\
		ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c	\
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c	\
		ft_substr.c ft_strjoin.c ft_strnbr.c ft_split.c ft_strmapi.c ft_strnjoin.c	\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar.c	\
		ft_putendl.c ft_putstr.c ft_putnbr.c ft_isspace.c ft_numlen.c ft_strcat.c	\
		ft_strcmp.c ft_strcpy.c ft_strncat.c ft_strncpy.c ft_strndup.c ft_strstr.c	\
		ft_strnew.c ft_strtrim.c get_next_line.c ft_itoa_base.c ft_itoa.c			\
		ft_utoa_base.c ft_free_cache.c 

SRCS_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c 				\
		ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstdelone_bonus.c 				\
		ft_lstiter_bonus.c ft_lstclear_bonus.c

OBJECTS = $(SRCS:%.c=%.o)

OBJECTS_B = $(SRCS_B:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

$(OBJECTS) : $(SRCS)
		gcc $(CFLAGS) $(SRCS)

$(OBJECTS_B) : $(SRCS_B)
		gcc $(CFLAGS) $(SRCS_B)

bonus : fclean $(OBJECTS) $(OBJECTS_B)
	ar rcs libft.a $(OBJECTS) $(OBJECTS_B)

clean : 
	rm -f $(OBJECTS) $(OBJECTS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re clean fclean
