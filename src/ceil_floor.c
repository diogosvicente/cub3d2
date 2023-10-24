/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:50:36 by dioda-si          #+#    #+#             */
/*   Updated: 2023/10/24 20:50:41 by dioda-si         ###   ########.fr       */
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
