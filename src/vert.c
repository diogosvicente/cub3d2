/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:55:27 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/04 18:32:50 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	mapdefvert(t_cast *tmp, t_hit *vert, float angle)
{
	if (mapwall(vert->xcheck, vert->ycheck))
	{
		vert->hity = vert->touchy;
		vert->hitx = vert->touchx;
		vert->content = mapatvert(angle);
		vert->wallhit = TRUE;
		return (TRUE);
	}
	else
	{
		vert->touchy += tmp->ystep;
		vert->touchx += tmp->xstep;
	}
	return (FALSE);
}

static void	insidevert(t_cast *tmp, t_hit *vert, t_all *all, float angle)
{
	int	cols;
	int	rows;

	cols = all->cols * TILE_SIZE;
	rows = all->rows * TILE_SIZE;
	vert->touchy = tmp->intrcpty;
	vert->touchx = tmp->intrcptx;
	while (vert->touchx >= 0 && vert->touchx <= cols
		&& vert->touchy >= 0 && vert->touchy <= rows)
	{
		vert->ycheck = vert->touchy;
		vert->xcheck = vert->touchx;
		if (tmp->lookright == FALSE)
			vert->xcheck = vert->touchx - 1;
		if (mapdefvert(tmp, vert, angle) == TRUE)
			break ;
	}
}

void	vertical(t_cast *tmp, float angle, t_all *all)
{
	float	ta;

	ta = tan(angle);
	tmp->vert.wallhit = FALSE;
	tmp->vert.hity = 0;
	tmp->vert.hitx = 0;
	tmp->vert.content = 0;
	// encontrar a coordenada de x mais proxima da intersecao vertical
	tmp->intrcptx = floor(all->player.px / TILE_SIZE) * TILE_SIZE;
	if (tmp->lookright == TRUE)
		tmp->intrcptx += TILE_SIZE;
	// encontrar a coordenada de y mais proxima da vertical 
	tmp->intrcpty = all->player.py + (tmp->intrcptx - all->player.px) * ta;
	//calcular incremento de x e y
	tmp->xstep = TILE_SIZE;
	if (tmp->lookright == FALSE)
		tmp->xstep *= -1;
	tmp->ystep = TILE_SIZE * ta;
	if (tmp->lookdown == FALSE && tmp->ystep > 0)
		tmp->ystep *= -1;
	if (tmp->lookdown == TRUE && tmp->ystep < 0)
		tmp->ystep *= -1;
	insidevert(tmp, &tmp->vert, all, angle);
}
