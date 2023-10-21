/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:32:38 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/21 13:08:10 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	ceil_floor(t_all *all)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		y = -1;
		while (++y < WINDOW_HEIGHT)
		{
			if (y >= WINDOW_HEIGHT / 2)
				all->img.colorbuffer[(WINDOW_WIDTH * y) + x] = all->color_fl;
			else
				all->img.colorbuffer[(WINDOW_WIDTH * y) + x] = all->color_cl;
		}
	}
}

void	start_wall(t_all *all) //TODO: rebuild this part to up the texture tennho 4 structs de cardeais fazer uma função generica pra cada 1. start wall gerencia e chama 1 função passando cada struct como parametro.
{
	int	width;
	int	i;
	int	height;
	const char	*path[4] = {"./fig/64.xpm",
		"./fig/sas.xpm",
		"./fig/miltank.xpm",
		"./fig/120.xpm"
	};

	i = 0;
	while (i < 4)
	{
		all->text[i].path = (char *)path[i];
		all->text[i].img_ptr = mlx_xpm_file_to_image(all->render,
				 all->text[i].path, &width, &height);
		all->text[i].wallbuffer = (int *)mlx_get_data_addr(all->text[i].img_ptr,
			&all->text[i].bpp,
			&all->text[i].size,
			&all->text[i].endian);
		i++;
	}
}

static void	render_wall(t_wall *wall, t_all *all, int x)
{
	int	y;
	int	color;
	int	tn;

	tn = all->rays[x].wallhitcontent - 1; //TODO: rebuild, with return based content return by lookup, lookleft number; map.c onde content vai ser de 1 a 4 onde 1-> S, 2 -> N, 3 -> E, 4 -> W (pode estar errado) basico if/else 
	y = wall->toppixel;
	if (all->rays[x].washitver)
		wall->offsetx = (int)all->rays[x].wallhity % TILE_SIZE;
	else
		wall->offsetx = (int)all->rays[x].wallhitx % TILE_SIZE;
	while (y < wall->botpixel)
	{
		wall->disttop = y + (wall->stripheight / 2) - (WINDOW_HEIGHT / 2);
		wall->offsety = wall->disttop * ((float)TILE_SIZE / wall->stripheight);
		color = all->text[tn].wallbuffer[(TILE_SIZE * wall->offsety) + wall->offsetx]; //tn used here // Wallbuffer na posição /\ // deve ser definida
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
