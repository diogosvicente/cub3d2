/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:45:16 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/20 15:54:33 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	keyboard(int keycode, t_all *all)
{
	//printf("%d\n", keycode);
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
	{
		//free_game(all);
		exit(42);
	}
	return (42);
}

int	key_solta(int keycode, t_all *all)
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
	(void)all;
	exit(42);
}
