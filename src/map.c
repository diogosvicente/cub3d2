/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:11:36 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/23 19:31:52 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	mapatvert(float angle)
{
	int	right;

	if (angle < 0.5 * PI || angle > 1.5 * PI)
		right = TRUE;
	else
		right = FALSE;
	if (right == TRUE)
		return (3);
	return (4);
}

int	mapathorz(float angle)
{
	int	down;

	if (angle > 0 && angle < PI)
		down = TRUE;
	else
		down = FALSE;
	if (down == TRUE)
		return (1);
	return (2);
}


int	mapwall(float x, float y, t_all *all)
{
	int	mapx;
	int	mapy;

	if (x < 0 || x >= all->cols * TILE_SIZE
		|| y < 0 || y >= all->rows * TILE_SIZE)
		return (TRUE);
	mapx = floor(x / TILE_SIZE);
	mapy = floor(y / TILE_SIZE);
	if (all->map[mapy][mapx] != '0')
		return (1);
	return (0);
}
