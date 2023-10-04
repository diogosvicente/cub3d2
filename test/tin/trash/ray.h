#ifndef RAY_H
#define RAY_H

#include "defs.h"
#include "player.h"

typedef struct s_ray
{
	float	rayAngle;
	float	wallHitX;
	float	wallHitY;
	float	distance;
	int	wasHitVer;
	int	wallHitContent;
} ray_t;

extern ray_t rays[NUM_RAYS];

float	normalizeAngle(float angle);
float	distanceBetweenPoints(float x1, float y1, float x2, float y2);
void	castRay(float rayAngle, int stripid, t_all *all);
void	castAllRays(t_all *all);
void	renderRays(t_all *all);
#endif
