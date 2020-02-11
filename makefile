# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/11 08:51:16 by adorigo           #+#    #+#              #
#    Updated: 2020/02/11 08:51:18 by adorigo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MINILIBX_PATH = ./minilibx_opengl

SRC_PATH = src
SRC_NAME = check_grid.c \
			config_grid.c \
			cub_init.c \
			cub3d_setting.c \
			errors.c \
			form_checker.c \
			free.c \
			ft_raycasting.c \
			main.c \
			config.c \
			player.c \
			render.c \
			run_mlx.c \
			screen_shot.c \
			screen.c \
			sp_screen.c \
			sprite.c \
			texture.c


OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Wextra

CPPFLAGS = -I includes -I libft -I minilibx_opengl
LDFLAGS = -L libft -L minilibx_opengl
LDLIBS = -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: libft minilibx_all $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@rm -rf screenshot.bmp
	@echo "" > screenshot.bmp
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Compilation of cub3D:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -pv $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

libft:
	@make -C libft

clean:
	@make -C libft clean
	@make -C minilibx_opengl clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean:
	@make -C libft fclean
	@make -C minilibx_opengl clean
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)

re: fclean all

bonus: all

minilibx_all:
	make -C $(MINILIBX_PATH) all

.PHONY: all clean fclean re libft