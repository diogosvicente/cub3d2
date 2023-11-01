/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:45:16 by kade-sou          #+#    #+#             */
/*   Updated: 2023/11/01 16:04:55 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	keyboard(int keycode, t_all *all)
{
	if (keycode == 'w')
		all->player.walkdirection = 1;
	else if (keycode == 's')
		all->player.walkdirection = -1;
	else if (keycode == 'a')
	{
		all->player.walkdirection = -1;
		all->player.walkside = 1.57;
	}
	else if (keycode == 'd')
	{
		all->player.walkdirection = 1;
		all->player.walkside = 1.57;
	}
	else if (keycode == 65361)
		all->player.turndirection = -1;
	else if (keycode == 65363)
		all->player.turndirection = 1;
	else if (keycode == 65307)
		xclose(keycode, all);
	return (42);
}

int	key_free(int keycode, t_all *all)
{
	if (keycode == 'w' || keycode == 's')
		all->player.walkdirection = 0;
	else if (keycode == 'a' || keycode == 'd')
	{
		all->player.walkdirection = 0;
		all->player.walkside = 0;
	}
	else if (keycode == 65361 || keycode == 65363)
		all->player.turndirection = 0;
	return (42);
}

int	xclose(int keycode, t_all *all)
{
	(void)keycode;
	cleaning(all);
	clear_map(all->map);
	free(all->rays);
	mlx_destroy_image(all->render, all->no.img.img_ptr);
	mlx_destroy_image(all->render, all->ea.img.img_ptr);
	mlx_destroy_image(all->render, all->we.img.img_ptr);
	mlx_destroy_image(all->render, all->so.img.img_ptr);
	mlx_clear_window(all->render, all->win);
	mlx_destroy_window(all->render, all->win);
	free(all->render);
	exit(42);
}
