#include "defs.h"

void	renderwallProjection(t_all *all)
{
	for(int i = 0; i < NUM_RAYS; i++)
	{
		float perpDistance = all->rays[i].distance * cos(all->rays[i].rayAngle - all->player.rotationAngle);
		float distanceProjPlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		float projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;
		int wallStripHeight = (int)projectedWallHeight;
		int wallTopPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
		wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

		int wallBottonPixel = (WINDOW_HEIGHT / 2) + (wallStripHeight / 2);
		wallBottonPixel = wallBottonPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottonPixel;

		//calculate OFFSETX
		int	offsetX;
		if(all->rays[i].wasHitVer)
		{
			offsetX = (int)all->rays[i].wallHitY % TILE_SIZE;
		}
		else
		{
			// perform offset for the vertical hit
			offsetX = (int)all->rays[i].wallHitX % TILE_SIZE;
		}

		//get the correct idnumber from the map contente
		
		//int textnum = all->rays[i].wallHitContent - 1;
		//int	texture_width = jorginho[textnum].width;
		//int	texture_height = jorginho[textnum].height;
		//todo: render the wall from walltoppixel to wallbottonpixel
		//printf("%d\n", i);
		for(int y = wallTopPixel; y < wallBottonPixel; y++)
		{
			//calculate offsetY
			int distanceFromTop = y + (wallStripHeight / 2) - (WINDOW_HEIGHT / 2);
			int offsetY = distanceFromTop * ((float)TEXTURE_HEIGHT / wallStripHeight);
			//int offsetY = distanceFromTop * ((float)texture_height / wallStripHeight);

			//set the color of the wall based the coclor from the texture
			//uint32_t texelColor = jorginho[textnum].texture_buffer[(TEXTURE_WIDTH * offsetY) + offsetX];
			uint32_t texelColor = all->wallTexture[(TEXTURE_WIDTH * offsetY) + offsetX];
			//uint32_t texelColor = wallTexture[(texture_width * offsetY) + offsetX];
			all->img.colorBuffer[(WINDOW_WIDTH * y) + i] = texelColor;
		}
	}
}


