/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorigo <adorigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:49:00 by adorigo           #+#    #+#             */
/*   Updated: 2020/01/17 09:24:50 by adorigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "libs/libft/libft.h"
# include "libs/minilibx_opengl/mlx.h"
# include "includes/key.h"

# define TEX_N 0
# define TEX_S 1
# define TEX_W 2
# define TEX_E 3
# define TEX_O 4
# define RMAX_W 2560
# define RMAX_H 1440
# define RMIN_W 480
# define RMIN_H 320

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef	struct		s_tex
{
	char			*path[5];
	void			*img[5];
	void			*data[5];
	int				wh[5][2];
	int				bpp;
	int				size_line;
	int				endian;
}					t_tex;

typedef struct		s_config
{
	int				res_w;
	int				res_h;
	int				grid_w;
	int				grid_h;
	int				color_f;
	int				color_c;
	t_tex			*tex;
}					t_config;

typedef struct		s_player
{
	t_pos			*pos;
	t_pos			*dir;
	t_pos			*plane;
	t_pos			*cam;
	t_pos			*step;
	double			mov_speed;
	double			rot_speed;
	int				rot_dir;
	int				mov_dir;
}					t_player;

typedef struct		s_ray
{
	t_pos			*dir;
	double			dist_x;
	double			dist_y;
	t_pos			*delta_dist;
	double			perp_wdist;
	int				w_hit;
	int				w_height;
	int				w_type;
	int				side;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			dist;
	struct s_sprite	*next;
}					t_sprite;

typedef struct s_cub3d
{
	t_config		*config;
	t_player		*player;
	t_ray			*ray;
	t_config		*conf;
	t_tex			*tex;
	t_sprite		*sp;
	// char			**grid;
	void			*mlx;
	void			*win;
	void			*img;
	void			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_cub3d;

int					raycasting(t_cub3d *cub3d);
int					free_all(t_cub3d *cub3d, int ret);
int					err_free(int erno, char *msg, t_cub3d *cub3d, int ret);
int					msg_err(int erno, char *msg, int ret);
int					cub_init(t_cub3d *cub);
int					set_screen(t_cub3d *cub3d);
int					run_mlx(t_cub3d *cub3d);

#endif
