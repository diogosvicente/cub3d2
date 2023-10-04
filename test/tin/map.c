#include "defs.h"

static const	int			map[MAP_NUM_ROWS][MAP_NUM_COLS] =
{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1, 1, 1, 1, 1, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{ 1, 0, 0, 0, 1, 0, 3, 0, 2, 0, 1, 0, 2, 0, 3, 0, 1, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


int	mapWall(float x, float y)
{
	if (x < 0 || x >= MAP_NUM_COLS * TILE_SIZE || y < 0 || y >= MAP_NUM_ROWS * TILE_SIZE)
		return TRUE;
	int	mapx = floor(x / TILE_SIZE);
	int	mapy = floor(y / TILE_SIZE);

	return map[mapy][mapx] != 0;
}

int	getmapat(int i, int j)
{
	return map[i][j];
}

int	isinsidemap(float x, float y)
{
	return (x >= 0 && x <=MAP_NUM_COLS * TILE_SIZE && y >= 0 && y <= MAP_NUM_ROWS * TILE_SIZE);
}

void	renderMap(t_all *all)
{
	int i, j, tileX, tileY, tileColor;
	for (i = 0; i < MAP_NUM_ROWS; i++)
	{
		for(j = 0; j < MAP_NUM_COLS; j++)
		{
			tileX = j * TILE_SIZE;
			tileY = i * TILE_SIZE;
			tileColor = map[i][j] != 0 ? 0xFFFFFFFF : 0;

			drawRect(all, tileX * MINI_MAP_SCALE, 
				tileY * MINI_MAP_SCALE, 
				TILE_SIZE * MINI_MAP_SCALE, 
				TILE_SIZE * MINI_MAP_SCALE,
				tileColor
				);
		}
	}

}
