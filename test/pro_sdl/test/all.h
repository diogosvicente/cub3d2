#ifndef ALL_H
#define	ALL_H

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

#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdint.h>
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

/*typedef struct s_ray
{
	float	rayAngle;
	float	wallHitX;
	float	wallHitY;
	float	distance;
	int	wasHitVer;
	int	isRFup;
	int	isRFdown;
	int	isRFleft;
	int	isRFright;
	int	wallHitContent;
} t_ray;*/

typedef struct s_all 
{
	SDL_Window	*window;
	SDL_Renderer	*render;
	SDL_Event	event;
	int		isGamingRuning;
	int	ticksLastFrame;
	t_play		player;
	//t_ray		rays;
}		t_all;

/*typedef struct s_texture{
	upng_t *upngtext;
	int width;
	int height;
	uint32_t *texture_buffer;
} texture_t;

void	loadWallTextures();
void	freewall();
*/
#endif
