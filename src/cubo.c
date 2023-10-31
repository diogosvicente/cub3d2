/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:57:42 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/31 19:18:28 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	setup(t_all *all)
{
	all->rays = malloc(sizeof(t_ray) * NUM_RAYS);
	init_player(&all->player);
	start_position(all, all->map);
}

void	event(t_all *all)
{
	mlx_hook(all->win, 2, 1L << 0, &keyboard, all);
	mlx_hook(all->win, 3, 1L << 1, &key_free, all);
	mlx_hook(all->win, 17, 1L << 2, &xclose, all);
}

void	update(t_all *all)
{
	move_player(all);
	castallrays(all);
}

int	render(void *res)
{
	t_all	*all;

	all = (t_all *)res;
	all->img.img_ptr = mlx_new_image(all->render,
			WINDOW_WIDTH,
			WINDOW_HEIGHT);
	all->img.colorbuffer = (int *)mlx_get_data_addr(all->img.img_ptr,
			&all->img.bpp,
			&all->img.size,
			&all->img.endian);
	update(all);
	ceil_floor(all);
	wall_project(all);
	mlx_put_image_to_window(all->render, all->win, all->img.img_ptr, 0, 0);
	mlx_destroy_image(all->render, all->img.img_ptr);
	return (42);
}

void	render_game(t_all *all)
{
	all->render = mlx_init();
	all->win = mlx_new_window(all->render,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			"Cub3d");
	setup(all);
	event(all);
	mlx_loop_hook(all->render, &render, all);
	mlx_loop(all->render);
}
