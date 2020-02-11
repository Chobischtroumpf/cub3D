# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 20:06:13 by alessandro        #+#    #+#              #
#    Updated: 2020/02/11 08:08:06 by adorigo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MINILIBX_PATH = ./libs/minilibx_opengl
LIBFT_PATH = ./libs/libft

CC = clang
CFLAGS = -Wall -Wextra -Werror
INCLUDE_FLAGS = -I./includes/ -I./libs/libft -I./libs/minilibx_opengl
LDFLAGS = -L libft -L minilibx_opengl
LDLIBS = -lft -lm -lmlx -framework OpenGL -framework AppKit

SRCS_LIST = \
	check_grid.c \
	config_grd.c \
	cub_init.c \
	cub3d_setting.c \
	errors.c \
	form_checker.c \
	free.c \
	ft_raycasting.c \
	main.c \
	parsing \
	player.c \
	render.c \
	run_mlx.c \
	screen_shot.c \
	screen.c \
	sp_screen.c \
	sprite.c \
	texture.c

SRCS_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/,$(SRCS_LIST))

OBJ_PATH = ./objs
OBJ_NAME = $(SRC_NAME):.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: libft minilibx $(NAME)

$(NAME) : $(OBJ) $(LIBFT_PATH)/libft.a
	@rm -rf screenshot.bmp
	@echo "" > screenshot.bmp
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

libft :
	@make -C $(LIBFT_PATH)

clean :
	@make -C $(LIBFT_PATH) clean
	@make -C $(MINILIBX_PATH) clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean :
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MINILIBX_PATH) clean
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)

re : fclean all

bonus : all

minilibx_all :
	make -C $(MINILIBX_PATH) all

.PHONY : all clean fclean re libft
