/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:32:38 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/23 19:32:10 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

//void	start_wall(t_all *all) TODO: rebuild this part to up the texture

// int	color;
// int	tn;

// tn = all->rays[x].wallhitcontent;
		//TODO: rebuild, with return
		// based content return by lookup, lookleft number; map.c
// y = wall->toppixel;

// wall->offsety = wall->disttop * 
			//((float)TILE_SIZE / wall->stripheight);
// color = all->text[tn].wallbuffer
			//[(TILE_SIZE * wall->offsety) + wall->offsetx]; tn used here

void	open_text(t_text *ref, t_all *all)
{
	ref->img.img_ptr = mlx_xpm_file_to_image(all->render,
			ref->path,
			&ref->width,
			&ref->height);
	ref->wallbuffer = (int *)mlx_get_data_addr(ref->img.img_ptr,
			&ref->img.bpp,
			&ref->img.size,
			&ref->img.endian);
}

void	start_wall(t_all *all)
{
	open_text(&all->no, all);
	open_text(&all->so, all);
	open_text(&all->we, all);
	open_text(&all->ea, all);
}

static int	pixel_color(t_wall *wall, t_all *all, int ref)
{
	int	color;
	int	y;
	int	x;

	y = wall->offsety * TILE_SIZE;
	x = y + wall->offsetx;
	color = 0;
	if (ref == 2)
		color = all->no.wallbuffer[x];
	else if (ref == 1)
		color = all->so.wallbuffer[x];
	else if (ref == 3)
		color = all->we.wallbuffer[x];
	else if (ref == 4)
		color = all->ea.wallbuffer[x];
	else
		color = 0xFFFFFFFF;
	return (color);
}

static void	render_wall(t_wall *wall, t_all *all, int x)
{
	int	y;
	int	color;

	y = wall->toppixel;
	if (all->rays[x].washitver)
		wall->offsetx = (int)all->rays[x].wallhity % TILE_SIZE;
	else
		wall->offsetx = (int)all->rays[x].wallhitx % TILE_SIZE;
	while (y < wall->botpixel)
	{
		wall->disttop = y + (wall->stripheight / 2) - (WINDOW_HEIGHT / 2);
		wall->offsety = wall->disttop * ((float)TILE_SIZE / wall->stripheight);
		color = pixel_color(wall, all, all->rays[x].wallhitcontent);
		all->img.colorbuffer[(WINDOW_WIDTH * y) + x] = color;
		y++;
	}
}

void	wall_project(t_all *all)
{
	int		i;
	float	co;
	float	distplane;
	t_wall	wall;

	i = 0;
	start_wall(all);
	distplane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		co = cos(all->rays[i].rayangle - all->player.rotationangle);
		wall.perpdist = all->rays[i].distance * co;
		wall.projheight = (TILE_SIZE / wall.perpdist) * distplane;
		wall.stripheight = (int)wall.projheight;
		wall.toppixel = (WINDOW_HEIGHT / 2) - (wall.stripheight / 2);
		if (wall.toppixel < 0)
			wall.toppixel = 0;
		wall.botpixel = (WINDOW_HEIGHT / 2) + (wall.stripheight / 2);
		if (wall.botpixel > WINDOW_HEIGHT)
			wall.botpixel = WINDOW_HEIGHT;
		render_wall(&wall, all, i);
		i++;
	}
}
