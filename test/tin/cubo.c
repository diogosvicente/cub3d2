#include "defs.h"

int	keyboard(int keycode, t_all *all)
{
	//printf("%d\n", keycode);
	if (keycode == 'w')
		all->player.walkDirection = 1;
	else if (keycode == 's')
		all->player.walkDirection = -1;
	else if (keycode == 'a')
		all->player.turnDirection = -1;
	else if (keycode == 'd')
		all->player.turnDirection = 1;
	else if (keycode == 65307)
	{
		//free_game(game);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

int	key_solta(int keycode, t_all *all)
{
	if (keycode == 'w' || keycode == 's')
		all->player.walkDirection = 0;
	else if (keycode == 'a' || keycode == 'd')
		all->player.turnDirection = 0;
	return (1);
}

int	xclose(int keycode, t_all *all)
{
	(void)keycode;
	(void)all;
	exit(1);
}

void	event(t_all *all)
{
	mlx_do_key_autorepeatoff(all->render);
	mlx_hook(all->win, 02, 1, &keyboard, all);
	//mlx_key_hook(all->win, &keyboard, all);
	mlx_hook(all->win, 03, 2, &key_solta, all);
	mlx_hook(all->win, 17, 0, &xclose, all);
}


void	setup(t_all *all)
{
	all->rays = malloc(sizeof(t_ray) * NUM_RAYS);
	init_player(&all->player);
	init_color(all);
}


void	update(t_all *all)
{
	float	deltaTime;
	deltaTime = 0.013;
	
	movePlayer(deltaTime, all);
	
	castAllRays(all);
}

int	render(void *res)
{

	t_all *all = (t_all *)res;

	all->img.img_ptr = mlx_new_image(all->render, WINDOW_WIDTH, WINDOW_HEIGHT);
	all->img.colorBuffer = (int *)mlx_get_data_addr(all->img.img_ptr, 
			&all->img.bpp,
			&all->img.size,
			&all->img.endian);

	update(all);
	
	clearColorBuffer(all, 0xFF00EE30);
	
	renderwallProjection(all);
	
	mlx_put_image_to_window(all->render, all->win, all->img.img_ptr, 0, 0);
	mlx_destroy_image(all->render, all->img.img_ptr);
	
	return (42);
}


int main()
{
	t_all	all;
	all.render = mlx_init();
	all.win = mlx_new_window(all.render, WINDOW_WIDTH, WINDOW_HEIGHT, "Cubinho");
	setup(&all);
	event(&all);
	mlx_loop_hook(all.render, &render, &all);
	mlx_loop(all.render);
}
