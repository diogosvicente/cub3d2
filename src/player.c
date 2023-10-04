/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:09:03 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/03 16:36:37 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

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
	if (!mapwall(new_px, new_py))
	{
		all->player.px = new_px;
		all->player.py = new_py;
	}
}
