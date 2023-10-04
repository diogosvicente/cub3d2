#ifndef DEFS_H
#define	DEFS_H

#define PI 3.14159265
#define TWO_PI 6.28318530

#define TILE_SIZE 64
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20

#define MINI_MAP_SCALE 0.2

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define TEXTURE_WIDTH 64
#define	TEXTURE_HEIGHT 64
#define FOV_ANGLE (60 * (PI / 180))
#define NUM_RAYS WINDOW_WIDTH

#define NUM_TEXTURE 3
#define FALSE 0
#define TRUE 1

#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)

#include <stdlib.h>
#include <math.h>

#include <stdint.h>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <limits.h>
//#include "upng.h"

typedef struct s_play
{
	float	px;
	float	py;
	float	width;
	float	height;
	int	turnDirection; //-1 for left, +1 for right
	int	walkDirection; //-1 for back, +1 for front
	float	rotationAngle;
	float	walkSpeed;
	float	turnSpeed;
}		t_play;

typedef struct s_ray
{
	float	rayAngle;
	float	wallHitX;
	float	wallHitY;
	float	distance;
	int	wasHitVer;
	int	wallHitContent;
} t_ray;

typedef struct s_all 
{
	SDL_Window	*window;
	SDL_Renderer	*render;
	SDL_Event	event;
	uint32_t	*colorBuffer;
	uint32_t	*wallTexture;
	int		isGamingRuning;
	int	ticksLastFrame;
	t_play		player;
	t_ray		*rays;
}		t_all;

///graphics.h///
int	inicializaçãoJanela(t_all *all);
void	destroyWindow(t_all *all);
void	clearColorBuffer(t_all *all, uint32_t color);
void	renderColorBuffer(t_all *all);
void	drawpixel(t_all *all, int x, int y, uint32_t color);
void	drawline(t_all *all, int x0, int x1, int y0, int y1, uint32_t color);
void	drawRect(t_all *all, int x, int y, int width, int height, uint32_t color);
void	init_color(t_all *all);
///map.h///
int	mapWall(float x, float y);
void	renderMap(t_all *all);
int	getmapat(int i, int j);
int	isinsidemap(float x, float y);

/// player.h ////
void	renderPlayer(t_all *all);
void	movePlayer(float delta, t_all *all);
void	init_player(t_play *player);

///wall.h///
void	renderwallProjection(t_all *all);

////Ray.h///////
float	normalizeAngle(float angle);
float	distanceBetweenPoints(float x1, float y1, float x2, float y2);
void	castRay(float rayAngle, int stripid, t_all *all);
void	castAllRays(t_all *all);
void	renderRays(t_all *all);

#endif
