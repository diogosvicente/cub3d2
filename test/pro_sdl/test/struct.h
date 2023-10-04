/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:42:30 by kade-sou          #+#    #+#             */
/*   Updated: 2023/09/26 20:32:28 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	float	rotation;
	float	wspeed;
	float	tspeed;
	int	turn;
	int	walk;
}		t_player;

typedef	struct	s_ray
{
	float	angle;
	float	hitX;
	float	hitY;
	float	distance;
	int	hitVertical;
	int	lookUp;
	int	lookDown;
	int	lookLeft;
	int	lookRight;
	int	content;
}		t_ray;

typedef	struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int	bpp;
	int	size;
	int	endian;
}		t_img;

typedef	struct	s_game
{
	void	*mlx_ptr;
	void	*win;
	t_img	img;
	t_ray	*rays;
	t_player	player;
}

#endif
