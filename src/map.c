/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:11:36 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/04 18:32:10 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static const int	map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 4},
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
		{ 3, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 4},
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 4},
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 4},
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 4},
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 4},
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
		{ 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
		{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
};

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


int	mapwall(float x, float y)
{
	int	mapx;
	int	mapy;

	if (x < 0 || x >= MAP_NUM_COLS * TILE_SIZE
		|| y < 0 || y >= MAP_NUM_ROWS * TILE_SIZE)
		return (TRUE);
	mapx = floor(x / TILE_SIZE);
	mapy = floor(y / TILE_SIZE);
	return (map[mapy][mapx] != 0);
}
