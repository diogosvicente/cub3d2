/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:57:15 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/20 20:35:03 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	init_player(t_play *player)
{
	player->width = 5;
	player->height = 5;
	player->turndirection = 0;
	player->walkdirection = 0;
	player->walkside = 0;
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
	if (angle > 0 && angle < PI)
		tmp->lookdown = TRUE;
	else
		tmp->lookdown = FALSE;
	if (angle < 0.5 * PI || angle > 1.5 * PI)
		tmp->lookright = TRUE;
	else
		tmp->lookright = FALSE;
}
