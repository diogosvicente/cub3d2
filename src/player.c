/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:09:03 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/23 20:07:00 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	looking_at(char c, t_play *player)
{
	if (c == 'N')
		player->rotationangle = PI * 1.5;
	if (c == 'S')
		player->rotationangle = PI * 0.5;
	if (c == 'W')
		player->rotationangle = TWO_PI;
	if (c == 'E')
		player->rotationangle = TWO_PI * 0.5;
}

void	start_position(t_all *all, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				looking_at(map[i][j], &all->player);
				map[i][j] = '0';
				all->player.px = j * TILE_SIZE + 1.5;
				all->player.py = i * TILE_SIZE - 1.5;
			}
			j++;
		}
		i++;
	}
}

void	move_player(t_all *all)
{
	float	movestep;
	float	new_px;
	float	new_py;
	float	delta;
	float	l;

	l = all->player.walkside;
	delta = 0.015;
	all->player.rotationangle += all->player.turndirection
		* all->player.turnspeed * delta;
	movestep = all->player.walkdirection * all->player.walkspeed * delta;
	new_px = all->player.px + cos(all->player.rotationangle + l) * movestep;
	new_py = all->player.py + sin(all->player.rotationangle + l) * movestep;
	if (!mapwall(new_px, new_py, all))
	{
		all->player.px = new_px;
		all->player.py = new_py;
	}
}
