#include "defs.h"

void	init_player(t_play *player)
{
	player->px = WINDOW_WIDTH / 2; //start in the center of map
	player->py = WINDOW_HEIGHT / 2; //start in the center
	player->width = 5;
	player->height = 5;
	player->turnDirection = 0;
	player->walkDirection = 0;
	player->rotationAngle = PI / 2;
	player->walkSpeed = 150;
	player->turnSpeed = 45 * (PI / 180);
}

void	movePlayer(float delta, t_all *all)
{
	float movestep, newPx, newPy;
	all->player.rotationAngle += all->player.turnDirection * all->player.turnSpeed * delta;
	//printf("%f\t %f\n", all->player.rotationAngle, delta);
	movestep = all->player.walkDirection * all->player.walkSpeed * delta;
	newPx = all->player.px + cos(all->player.rotationAngle) * movestep;
	newPy = all->player.py + sin(all->player.rotationAngle) * movestep;
	
	if (!mapWall(newPx, newPy)){
		all->player.px = newPx;
		all->player.py = newPy;
	};
	//TODO: wall colisão

}

void	renderPlayer(t_all *all)
{
	//int raio = 40;
	drawRect(all,
		all->player.px * MINI_MAP_SCALE,
		all->player.py * MINI_MAP_SCALE,
		all->player.width * MINI_MAP_SCALE,
		all->player.height * MINI_MAP_SCALE,
		0xFFFFFFFF
	);
}



