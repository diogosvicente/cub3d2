/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:40:08 by kade-sou          #+#    #+#             */
/*   Updated: 2023/11/06 11:58:17 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# define PI 3.14159265
# define TWO_PI 6.28318530

# define TILE_SIZE 64

# define FOV_ANGLE 1.0471975512

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define NUM_RAYS WINDOW_WIDTH

# define FALSE 0
# define TRUE 1

# include <stdio.h>
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_play
{
	float	px;
	float	py;
	float	width;
	float	height;
	int		turndirection;
	int		walkdirection;
	float	walkside;
	float	rotationangle;
	float	walkspeed;
	float	turnspeed;
}		t_play;

typedef struct s_wall
{
	float	perpdist;
	float	projheight;
	int		stripheight;
	int		toppixel;
	int		botpixel;
	int		offsetx;
	int		offsety;
	int		disttop;
}		t_wall;

typedef struct s_hit
{
	float	hity;
	float	hitx;
	int		content;
	int		wallhit;
	float	touchy;
	float	touchx;
	float	ycheck;
	float	xcheck;
}		t_hit;

typedef struct s_cast
{
	int		lookdown;
	int		lookright;
	float	intrcptx;
	float	intrcpty;
	float	xstep;
	float	ystep;
	t_hit	horz;
	t_hit	vert;
}		t_cast;

typedef struct s_ray
{
	float	rayangle;
	float	wallhitx;
	float	wallhity;
	float	distance;
	int		washitver;
	int		wallhitcontent;
}		t_ray;

typedef struct s_img
{
	void	*img_ptr;
	int		*colorbuffer;
	int		bpp;
	int		size;
	int		endian;
}		t_img;

typedef struct s_text
{
	int		width;
	int		height;
	char	*path;
	int		*wallbuffer;
	t_img	img;
}		t_text;

typedef struct s_all
{
	void		*render;
	void		*win;
	int			cols;
	int			rows;
	int			color_fl;
	int			color_cl;
	char		**map;
	t_play		player;
	t_ray		*rays;
	t_cast		cst;
	t_img		img;
	t_text		no;
	t_text		so;
	t_text		we;
	t_text		ea;
}		t_all;

/////////// cubo.c //////////////
void	render_game(t_all *all);

/////////// parser.c ///////////
int		check_fd(char *file);
void	check_cub(char *arg);

/////////// init.c /////////////
void	init_player(t_play *player);
void	init_tmp(t_cast *tmp);
void	check_view(t_cast *tmp, float angle);

////////////event.c//////////////
int		xclose(int keycode, t_all *all);
int		xclose2(t_all *all);
int		keyboard(int keycode, t_all *all);
int		key_free(int keycode, t_all *all);

////////// player.c ////////////
void	move_player(t_all *all);
void	start_position(t_all *all, char **map);

///////// ray.c ///////////////
void	castallrays(t_all *all);

//////////// horz.c //////////
void	horizontal(t_cast *tmp, float angle, t_all *all);

/////////// vert.c /////////////
void	vertical(t_cast *tmp, float angle, t_all *all);

////////// util.c //////////////
float	dist_point(t_play *p, t_hit *ref);

///////////// map.c //////////////
int		mapatvert(float angle);
int		mapathorz(float angle);
int		mapwall(float x, float y, t_all *all);

////////// graphic.c /////////////
void	ceil_floor(t_all *all);
void	wall_project(t_all *all);

////////// files.c //////////////
void	check_file(int fd, t_all *all, int start);

///////// check.c /////////////
int		check_text(char *line, const char *dir, t_text *ref);

///////// maping.c ///////////
int		start_map(char *line, int start);
char	**final_map(char *buff_map);
char	*concat_map(char *line, char *buff);

//////// color.c //////////////
int		check_color(char *line, const char *dir, t_all *all);

//////// treatmap.c //////////
int		is_map_okay(t_all *all);

//////// utils.c ////////////
void	clear_map(char **map);
void	cleaning(t_all *all);
int		lentab(char *line, char c);

////// validation.c ////////////
char	**map_for_validation(char **map, int cols, int rows);
void	flood(char **map, int y, int x, t_all *all);

#endif
