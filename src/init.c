/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:57:15 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/09 16:48:46 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_player(t_play *player)
{
	player->px = (MAP_NUM_COLS * TILE_SIZE) / 2; //start in the center of map
	player->py = (MAP_NUM_ROWS * TILE_SIZE) / 2; //start in the center
	player->width = 5;
	player->height = 5;
	player->turndirection = 0;
	player->walkdirection = 0;
	player->walkside = 0;
	player->rotationangle = PI * 0.5; //start VIEW
	player->walkspeed = 150;
	player->turnspeed = 45 * (PI / 180);
}

void	init_tmp(t_cast *tmp)
{
	tmp->lookdown = 0;
	tmp->lookright = 0;
	tmp->intrcptx = 0;
	tmp->intrcpty = 0;
	tmp->xstep = 0;
	tmp->ystep = 0;
}

void	check_view(t_cast *tmp, float angle)
{
	//printf("%f\n", angle);
	if (angle > 0 && angle < PI)
		tmp->lookdown = TRUE;
	else
		tmp->lookdown = FALSE;
	if (angle < 0.5 * PI || angle > 1.5 * PI)
		tmp->lookright = TRUE;
	else
		tmp->lookright = FALSE;
}
