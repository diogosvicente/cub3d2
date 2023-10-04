#ifndef PLAYER_H
#define PLAYER_H

#include "def.h"
#include "map.h"
#include "graphics.h"

void	renderPlayer(t_all *all);
void	movePlayer(float delta, t_all *all);
void	init_player(t_play *player);

#endif
