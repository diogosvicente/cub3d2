#ifndef MAP_H
#define MAP_H

#include "defs.h"
#include "graphics.h"

//#define MAP_NUM_ROWS 13
//#define MAP_NUM_COLS 20

int	mapWall(float x, float y);
void	renderMap(t_all *all);
int	getmapat(int i, int j);
int	isinsidemap(float x, float y);

#endif
