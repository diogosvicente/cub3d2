#include "defs.h"

//ray_t all->rays[NUM_RAYS];

float	normalizeAngle(float angle)
{
	angle = remainder(angle, TWO_PI);

	//printf("%f\n", angle);
	if (angle < 0)
	{
		angle = TWO_PI + angle;
	}
	return (angle);
}

float	distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void	castRay(float rayAngle, int stripid, t_all *all)
{
	//rayAngle = normalizeAngle(rayAngle);

	int	isRFdown = rayAngle > 0 && rayAngle < PI;
	int	isRFup = !isRFdown;
	int	isRFright = rayAngle < 0.5 * PI || rayAngle > 1.5 * PI;
	int	isRFleft = !isRFright;

//	printf("%d\n", isRFdown);
	float	xintercept, yintercept;
	float	xstep, ystep;

	/////////////////////////////////////////////////////
	// CONSTRUCTOR HORIZONTAL INTERSECTION CODE ///
	///////////////////////////////////////////////////

	int	foundHorzWallhit = FALSE;
	float	horzWallHitX = 0;
	float	horzWallHitY = 0;
	int	horzWallContent = 0;
	
	// Find the y-coordinate of the closest horizontal grid intersection
	yintercept = floor(all->player.py / TILE_SIZE) * TILE_SIZE;
	yintercept += isRFdown ? TILE_SIZE : 0;

	//Find the x-coordinate of the closest horizontal grid intersection
	xintercept = all->player.px + (yintercept - all->player.py) / tan(rayAngle);
	//calculate the increment xstep and y step

	ystep = TILE_SIZE;
	ystep *= isRFup ? -1 : 1;

	xstep = TILE_SIZE / tan(rayAngle);
	xstep *= (isRFleft && xstep > 0) ? -1 : 1;
	xstep *= (isRFright && xstep < 0) ? -1 : 1;
	
	float	nextHTouchX = xintercept; 
	float	nextHTouchY = yintercept;

	//while(isinsidemap(nextHTouchX, nextHTouchY)
	while(nextHTouchX >= 0 && nextHTouchX <= MAP_NUM_COLS * TILE_SIZE 
			&& nextHTouchY >= 0 && nextHTouchY <= MAP_NUM_ROWS * TILE_SIZE)
	{
		float xToCheck = nextHTouchX;
		float yToCheck = nextHTouchY + (isRFup ? -1 : 0);

		if (mapWall(xToCheck, yToCheck)){
			horzWallHitX = nextHTouchX;
			horzWallHitY = nextHTouchY;
			//horzWallContent = map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
			horzWallContent = getmapat((int)floor(yToCheck / TILE_SIZE), (int)floor(xToCheck / TILE_SIZE));
			//printf("%d\n", horzWallContent);
			foundHorzWallhit = TRUE;
			break ;
		}
		else
		{
			nextHTouchX += xstep;
			nextHTouchY += ystep;
		}
	}

	/////////////////////////////////////////////////////
	// CONSTRUCTOR VERTICAL INTERSECTION CODE ///
	///////////////////////////////////////////////////

	int	foundVertWallhit = FALSE;
	float	vertWallHitX = 0;
	float	vertWallHitY = 0;
	int	vertWallContent = 0;
	
	// Find the x-coordinate of the closest horizontal grid intersection
	xintercept = floor(all->player.px / TILE_SIZE) * TILE_SIZE;
	xintercept += isRFright ? TILE_SIZE : 0;

	//Find the y-coordinate of the closest horizontal grid intersection
	yintercept = all->player.py + (xintercept - all->player.px) * tan(rayAngle);
	//calculate the increment xstep and y step

	xstep = TILE_SIZE;
	xstep *= isRFleft ? -1 : 1;

	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= (isRFup && ystep > 0) ? -1 : 1;
	ystep *= (isRFdown && ystep < 0) ? -1 : 1;
	
	float	nextVTouchX = xintercept; 
	float	nextVTouchY = yintercept;

	//while(isinsidemap(nextVTouchX, nextVTouchY)
	while(nextVTouchX >= 0 && nextVTouchX <= MAP_NUM_COLS * TILE_SIZE
			&& nextVTouchY >= 0 && nextVTouchY <= MAP_NUM_ROWS * TILE_SIZE)
	{
		float xToCheck = nextVTouchX + (isRFleft ? -1 : 0);
		float yToCheck = nextVTouchY;

		if (mapWall(xToCheck, yToCheck)){
			vertWallHitX = nextVTouchX;
			vertWallHitY = nextVTouchY;
			//vertWallContent = map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
			vertWallContent = getmapat((int)floor(yToCheck / TILE_SIZE), (int)floor(xToCheck / TILE_SIZE));
			foundVertWallhit = TRUE;
			break ;
		}
		else
		{
			nextVTouchX += xstep;
			nextVTouchY += ystep;
		}
	}
	// Calculate both horizontal and vertical hit distances and choose the smallest one 

	float	horzHitDistance = foundHorzWallhit 
		? distanceBetweenPoints(all->player.px, all->player.py, horzWallHitX, horzWallHitY) : INT_MAX;
	float	vertHitDistance = foundVertWallhit
		? distanceBetweenPoints(all->player.px, all->player.py, vertWallHitX, vertWallHitY) : INT_MAX;

	if (vertHitDistance < horzHitDistance)
	{
		all->rays[stripid].distance = vertHitDistance;
		all->rays[stripid].wallHitX = vertWallHitX;
		all->rays[stripid].wallHitY = vertWallHitY;
		all->rays[stripid].wallHitContent = vertWallContent;
		all->rays[stripid].wasHitVer = TRUE;
		all->rays[stripid].rayAngle = rayAngle;
	}
	else
	{
		all->rays[stripid].distance = horzHitDistance;
		all->rays[stripid].wallHitX = horzWallHitX;
		all->rays[stripid].wallHitY = horzWallHitY;
		all->rays[stripid].wallHitContent = horzWallContent;
		all->rays[stripid].wasHitVer = FALSE;
		all->rays[stripid].rayAngle = rayAngle;
	}
	/*all->rays[stripid].rayAngle = rayAngle;
	all->rays[stripid].isRFdown = isRFdown;
	all->rays[stripid].isRFup = isRFup;
	all->rays[stripid].isRFleft = isRFleft;
	all->rays[stripid].isRFright = isRFright;*/
}

void	castAllRays(t_all *all)
{
/*	float rayAngle = all->player.rotationAngle - (FOV_ANGLE / 2);

	for (int stripid = 0; stripid < NUM_RAYS; stripid++)
	{
		castRay(rayAngle, stripid, all);
		rayAngle += FOV_ANGLE / NUM_RAYS;
		//printf("%f\t %f\n",rayAngle, FOV_ANGLE / NUM_RAYS);
	}*/
	float dispro = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);

	for (int stripid = 0; stripid < NUM_RAYS; stripid++)
	{
		float angle = all->player.rotationAngle + 
			atan((stripid - NUM_RAYS/ 2) / dispro);
		angle = normalizeAngle(angle);
		castRay(angle, stripid, all);
		//printf("%f\t %f\n",rayAngle, FOV_ANGLE / NUM_RAYS);
	}
}

void	renderRays(t_all *all)
{
	SDL_SetRenderDrawColor(all->render, 255, 0, 0, 255);

	for(int i = 0; i < NUM_RAYS; i++)
	{
		SDL_RenderDrawLine(
				all->render,
				MINI_MAP_SCALE * all->player.px,
				MINI_MAP_SCALE * all->player.py,
				MINI_MAP_SCALE * all->rays[i].wallHitX,
				MINI_MAP_SCALE * all->rays[i].wallHitY			
		);
	}
}


