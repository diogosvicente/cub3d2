/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:39:46 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/23 18:41:06 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

// tmp->horz.content = 0;
// after line above
// encontrar a coordenada de Y mais proxima da interseção horizontal

// encontrar a coordenada de X mais proxima da interseção horizontal
// tmp->intrcptx = all->player.px + (tmp->intrcpty - all->player.py) / ta;
// calcular o incremento dos proximos X e Y 

// calcular enquanto ta no mapa
// insidehorz(tmp, &tmp->horz, all, angle);

static int	mapdefhorz(t_cast *tmp, t_hit *horz, float angle, t_all *all)
{
	if (mapwall(horz->xcheck, horz->ycheck, all))
	{
		horz->hity = horz->touchy;
		horz->hitx = horz->touchx;
		horz->content = mapathorz(angle);
		horz->wallhit = TRUE;
		return (TRUE);
	}
	else
	{
		horz->touchy += tmp->ystep;
		horz->touchx += tmp->xstep;
	}
	return (FALSE);
}

static void	insidehorz(t_cast *tmp, t_hit *horz, t_all *all, float angle)
{
	int	cols;
	int	rows;

	cols = all->cols * TILE_SIZE;
	rows = all->rows * TILE_SIZE;
	horz->touchy = tmp->intrcpty;
	horz->touchx = tmp->intrcptx;
	while (horz->touchx >= 0 && horz->touchx <= cols
		&& horz->touchy >= 0 && horz->touchy <= rows)
	{
		horz->xcheck = horz->touchx;
		horz->ycheck = horz->touchy;
		if (tmp->lookdown == FALSE)
			horz->ycheck = horz->touchy - 1;
		if (mapdefhorz(tmp, horz, angle, all) == TRUE)
			break ;
	}
}

void	horizontal(t_cast *tmp, float angle, t_all *all)
{
	float	ta;

	ta = tan(angle);
	tmp->horz.wallhit = FALSE;
	tmp->horz.hity = 0;
	tmp->horz.hitx = 0;
	tmp->horz.content = 0;
	tmp->intrcpty = floor(all->player.py / TILE_SIZE) * TILE_SIZE;
	if (tmp->lookdown == TRUE)
		tmp->intrcpty += TILE_SIZE;
	tmp->intrcptx = all->player.px + (tmp->intrcpty - all->player.py) / ta;
	tmp->ystep = TILE_SIZE;
	if (tmp->lookdown == FALSE)
		tmp->ystep *= -1;
	tmp->xstep = TILE_SIZE / ta;
	if (tmp->lookright == FALSE && tmp->xstep > 0)
		tmp->xstep *= -1;
	if (tmp->lookright == TRUE && tmp->xstep < 0)
		tmp->xstep *= -1;
	insidehorz(tmp, &tmp->horz, all, angle);
}
