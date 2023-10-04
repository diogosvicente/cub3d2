/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:40:08 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/04 18:33:23 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# define PI 3.14159265
# define TWO_PI 6.28318530

# define TILE_SIZE 64

# define FOV_ANGLE (60 * (PI / 180))

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define NUM_RAYS WINDOW_WIDTH

# define FALSE 0
# define TRUE 1

///////// temp /////////

# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20

# include <limits.h>
# include <stdio.h>

////////////////////////

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_play
{
	float	px;
	float	py;
	float	width;
	float	height;
	int		turndirection; //-1 for left, +1 for right
	int		walkdirection; //-1 for back, +1 for front
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
	int		*wallbuffer;
	char	*path;
	int		bpp;
	int		size;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_all
{
	void		*render;
	void		*win;
	int			cols;
	int			rows;
	t_play		player;
	t_ray		*rays;
	t_img		img;
	t_img		text[4];
	t_cast		cst;
}		t_all;

/////////// init.c /////////////
void	init_player(t_play *player);
void	init_tmp(t_cast *tmp);
void	check_view(t_cast *tmp, float angle);

////////////event.c//////////////
int		xclose(int keycode, t_all *all);
int		keyboard(int keycode, t_all *all);
int		key_solta(int keycode, t_all *all);

////////// player.c ////////////
void	move_player(t_all *all);

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
int		mapwall(float x, float y);

////////// graphic.c /////////////
void	clear_buffer(t_all *all);
void	wall_project(t_all *all);

#endif
