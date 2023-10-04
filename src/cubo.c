/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:57:42 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/02 18:45:13 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	setup(t_all *all)
{
	all->rays = malloc(sizeof(t_ray) * NUM_RAYS);
	all->cols = MAP_NUM_COLS;
	all->rows = MAP_NUM_ROWS;
	init_player(&all->player);
}

void	event(t_all *all)
{
	mlx_do_key_autorepeatoff(all->render);
	mlx_hook(all->win, 02, 1, &keyboard, all);
	//mlx_key_hook(all->win, &keyboard, all);
	mlx_hook(all->win, 03, 2, &key_solta, all);
	mlx_hook(all->win, 17, 0, &xclose, all);
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
	clear_buffer(all); //só poem ceu e chão
	wall_project(all);// desenha parede
	mlx_put_image_to_window(all->render, all->win, all->img.img_ptr, 0, 0);
	mlx_destroy_image(all->render, all->img.img_ptr);
	//update(all);
	return (42);
}

int	main(int a, char **b)
{
	t_all	all;

	(void)a;
	(void)b;
	all.render = mlx_init();
	all.win = mlx_new_window(all.render,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			"Cubinho");
	setup(&all);
	event(&all);
	//render(&all);
	mlx_loop_hook(all.render, &render, &all);
	mlx_loop(all.render);
}
