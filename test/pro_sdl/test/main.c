#include "all.h"
#include <SDL2/SDL.h>

const	int			map[MAP_NUM_ROWS][MAP_NUM_COLS] =
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

int	mapWall(float x, float y);

struct s_ray
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
} rays[NUM_RAYS];

uint32_t *colorBuffer = NULL;
SDL_Texture *colorBufferTexture;

//texture_t jorginho[NUM_TEXTURE]; 

uint32_t *wallTexture = NULL;
uint32_t *textures[NUM_TEXTURE];

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

void	setup(t_all *all)
{
	all->window = NULL;
	all->render = NULL;
	all->isGamingRuning = FALSE;
	all->ticksLastFrame = 0;
	init_player(&all->player);
}

void	init_color(t_all *all)
{
	colorBuffer = (uint32_t *)malloc(sizeof(uint32_t) * (uint32_t)WINDOW_WIDTH * (uint32_t)WINDOW_HEIGHT);
	colorBufferTexture = SDL_CreateTexture(
			all->render, 
			SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING,
			WINDOW_WIDTH, 
			WINDOW_HEIGHT
	);
	wallTexture = (uint32_t *)malloc(sizeof(uint32_t) * (uint32_t)TEXTURE_WIDTH * (uint32_t)TEXTURE_HEIGHT);
	//load texture
	for(int x = 0; x < TEXTURE_WIDTH; x++)
	{
		for(int y = 0; y < TEXTURE_HEIGHT; y++)
		{
			/*if (x % 8 && y % 8)
				wallTexture[(TEXTURE_WIDTH * y) + x] = 0xFFFFFFFF;
			else
				wallTexture[(TEXTURE_WIDTH * y) + x] = 0x00000000;*/
			wallTexture[(TEXTURE_WIDTH * y) + x] = 0xFFFFFFFF;

		}
	}
	//loadWallTextures(&jorginho);
	
}

int	inicializaçãoJanela(t_all *all)
{
	//CONST INIT E FUNÇÃO DA PROPRIA SDL que retorna um status
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error de inicialização SDL. \n");
		return FALSE;
	}
	//sdl calcula resolução e me da o tamanho centralizado x e y
	all->window = SDL_CreateWindow(
		NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_BORDERLESS
	);
	if (!all->window){
		fprintf(stderr, "erro na criação da janela\n");
		return FALSE;
	}
	//-1 é para driver para o grafico, -1 é const para definir pega o default o padrao
	all->render = SDL_CreateRenderer(all->window, -1, 0);
	if (!all->render){
		fprintf(stderr, "erro na renderização\n");
		return FALSE;
	}
	SDL_SetRenderDrawBlendMode(all->render, SDL_BLENDMODE_BLEND);
	return TRUE;
}

void	destroyWindow(t_all *all)
{
	//freewall(&jorginho);
	free(colorBuffer);
	SDL_DestroyTexture(colorBufferTexture);
	SDL_DestroyRenderer(all->render);
	SDL_DestroyWindow(all->window);
	SDL_Quit();
}

void	renderPlayer(t_all *all)
{
	int raio = 40;
	SDL_SetRenderDrawColor(all->render, 255, 255, 255, 255);
	SDL_Rect playerRect = {
		all->player.px * MINI_MAP_SCALE,
		all->player.py * MINI_MAP_SCALE,
		all->player.width * MINI_MAP_SCALE,
		all->player.height * MINI_MAP_SCALE
	};
	SDL_RenderFillRect(all->render, &playerRect);
	SDL_RenderDrawLine(all->render, 
		MINI_MAP_SCALE * all->player.px,
		MINI_MAP_SCALE * all->player.py,
		MINI_MAP_SCALE * all->player.px + cos(all->player.rotationAngle) * raio,
		MINI_MAP_SCALE * all->player.py + sin(all->player.rotationAngle) * raio
	);
}

float	normalizeAngle(float angle)
{
	angle = remainder(angle, TWO_PI);

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
	rayAngle = normalizeAngle(rayAngle);

	int	isRFdown = rayAngle > 0 && rayAngle < PI;
	int	isRFup = !isRFdown;
	int	isRFright = rayAngle < 0.5 * PI || rayAngle > 1.5 * PI;
	int	isRFleft = !isRFright;

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
		int rest = isRFup ? -1 : 0;
		float yToCheck = nextHTouchY;
		if (isRFup)
			yToCheck = nextHTouchY - 1;
		printf("%d olha o ytocheck %f\n", rest, yToCheck);

		if (mapWall(xToCheck, yToCheck)){
			horzWallHitX = nextHTouchX;
			horzWallHitY = nextHTouchY;
			horzWallContent = map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
			//horzWallContent = getmapat((int)floor(yToCheck / TILE_SIZE), (int)floor(xToCheck / TILE_SIZE));
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
			vertWallContent = map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
			//vertWallContent = getmapat((int)floor(yToCheck / TILE_SIZE), (int)floor(xToCheck / TILE_SIZE));
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
		rays[stripid].distance = vertHitDistance;
		rays[stripid].wallHitX = vertWallHitX;
		rays[stripid].wallHitY = vertWallHitY;
		rays[stripid].wallHitContent = vertWallContent;
		rays[stripid].wasHitVer = TRUE;
	rays[stripid].rayAngle = rayAngle;
	}
	else
	{
		rays[stripid].distance = horzHitDistance;
		rays[stripid].wallHitX = horzWallHitX;
		rays[stripid].wallHitY = horzWallHitY;
		rays[stripid].wallHitContent = horzWallContent;
		rays[stripid].wasHitVer = FALSE;
	rays[stripid].rayAngle = rayAngle;
	}
	/*rays[stripid].rayAngle = rayAngle;
	rays[stripid].isRFdown = isRFdown;
	rays[stripid].isRFup = isRFup;
	rays[stripid].isRFleft = isRFleft;
	rays[stripid].isRFright = isRFright;*/
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
		float angle = all->player.rotationAngle + atan((stripid - NUM_RAYS/ 2) / dispro);
		castRay(angle, stripid, all);
		//printf("%f\t %f\n",rayAngle, FOV_ANGLE / NUM_RAYS);
	}
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
			tileColor = map[i][j] != 0 ? 255 : 0;

			SDL_SetRenderDrawColor(all->render, tileColor, tileColor, tileColor, 255);
			SDL_Rect mapTileRect = {
				tileX * MINI_MAP_SCALE, 
				tileY * MINI_MAP_SCALE, 
				TILE_SIZE * MINI_MAP_SCALE, 
				TILE_SIZE * MINI_MAP_SCALE
			};
			SDL_RenderFillRect(all->render, &mapTileRect);
		}
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
				MINI_MAP_SCALE * rays[i].wallHitX,
				MINI_MAP_SCALE * rays[i].wallHitY			
		);
	}
}

void	processInput(t_all *all)
{
	SDL_PollEvent(&all->event);

	switch (all->event.type)
	{
		case SDL_QUIT:
		{
		      all->isGamingRuning = FALSE;
		      break;
		}
		case SDL_KEYDOWN:{
			if (all->event.key.keysym.sym == SDLK_ESCAPE)
				all->isGamingRuning = FALSE;
			if (all->event.key.keysym.sym == SDLK_UP)
				all->player.walkDirection = +1;
			if (all->event.key.keysym.sym == SDLK_DOWN)
				all->player.walkDirection = -1;
			if (all->event.key.keysym.sym == SDLK_RIGHT)
				all->player.turnDirection = +1;
			if (all->event.key.keysym.sym == SDLK_LEFT)
				all->player.turnDirection = -1;
			break ;
		}
		case SDL_KEYUP:{
			if (all->event.key.keysym.sym == SDLK_UP)
				all->player.walkDirection = 0;
			if (all->event.key.keysym.sym == SDLK_DOWN)
				all->player.walkDirection = 0;
			if (all->event.key.keysym.sym == SDLK_RIGHT)
				all->player.turnDirection = 0;
			if (all->event.key.keysym.sym == SDLK_LEFT)
				all->player.turnDirection = 0;
			break ;
		}
	}
}

int	mapWall(float x, float y)
{
	if (x < 0 || x >= MAP_NUM_COLS * TILE_SIZE || y < 0 || y >= MAP_NUM_ROWS * TILE_SIZE)
		return TRUE;
	int	mapx = floor(x / TILE_SIZE);
	int	mapy = floor(y / TILE_SIZE);

	return map[mapy][mapx] != 0;
}

void	movePlayer(float delta, t_all *all)
{

	printf("%f\n", delta);
	float movestep, newPx, newPy;
	all->player.rotationAngle += all->player.turnDirection * all->player.turnSpeed * delta;
	movestep = all->player.walkDirection * all->player.walkSpeed * delta;
	newPx = all->player.px + cos(all->player.rotationAngle) * movestep;
	newPy = all->player.py + sin(all->player.rotationAngle) * movestep;
	
	if (!mapWall(newPx, newPy)){
		all->player.px = newPx;
		all->player.py = newPy;
	};
	//TODO: wall colisão

}

void	update(t_all *all)
{
	float	deltaTime;
	int	timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - all->ticksLastFrame);
	//while(!SDL_TICKS_PASSED(SDL_GetTicks(), all->ticksLastFrame + FRAME_TIME_LENGTH)); //gambiarra pra pausar e ter o fps exato em cada pc 

	if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
		SDL_Delay(timeToWait);

	deltaTime = (SDL_GetTicks() - all->ticksLastFrame) / 1000.0f;
	
	all->ticksLastFrame = SDL_GetTicks();
	
	movePlayer(deltaTime, all);
	
	castAllRays(all);
}

void	generateProjection(t_all *all)
{
	for(int i = 0; i < NUM_RAYS; i++)
	{
		float perpDistance = rays[i].distance * cos(rays[i].rayAngle - all->player.rotationAngle);
		float distanceProjPlane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		float projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;
		int wallStripHeight = (int)projectedWallHeight;
		int wallTopPixel = (WINDOW_HEIGHT / 2) - (wallStripHeight / 2);
		wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

		int wallBottonPixel = (WINDOW_HEIGHT / 2) + (wallStripHeight / 2);
		wallBottonPixel = wallBottonPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottonPixel;

		//calculate OFFSETX
		int	offsetX;
		if(rays[i].wasHitVer)
		{
			offsetX = (int)rays[i].wallHitY % TILE_SIZE;
		}
		else
		{
			// perform offset for the vertical hit
			offsetX = (int)rays[i].wallHitX % TILE_SIZE;
		}

		//get the correct idnumber from the map contente
		
		//int textnum = rays[i].wallHitContent - 1;
		//int	texture_width = jorginho[textnum].width;
		//int	texture_height = jorginho[textnum].height;
		//todo: render the wall from walltoppixel to wallbottonpixel
		for(int y = wallTopPixel; y < wallBottonPixel; y++)
		{
			//calculate offsetY
			int distanceFromTop = y + (wallStripHeight / 2) - (WINDOW_HEIGHT / 2);
			int offsetY = distanceFromTop * ((float)TEXTURE_HEIGHT / wallStripHeight);
			//int offsetY = distanceFromTop * ((float)texture_height / wallStripHeight);

			//set the color of the wall based the coclor from the texture
			//uint32_t texelColor = jorginho[textnum].texture_buffer[(TEXTURE_WIDTH * offsetY) + offsetX];
			uint32_t texelColor = wallTexture[(TEXTURE_WIDTH * offsetY) + offsetX];
			//uint32_t texelColor = wallTexture[(texture_width * offsetY) + offsetX];
			colorBuffer[(WINDOW_WIDTH * y) + i] = texelColor;
		}
	}
}

void	clearColorBuffer(uint32_t color)
{
	for(int x = 0; x < WINDOW_WIDTH; x++)
	{
		for(int y = 0; y < WINDOW_HEIGHT; y++)
		{
			if(y >= WINDOW_HEIGHT / 2)
				colorBuffer[(WINDOW_WIDTH * y) + x] = color;
			else
				colorBuffer[(WINDOW_WIDTH * y) + x] = 0xFFFF0000;
		}
	}
}

void	renderColorBuffer(t_all *all)
{
	SDL_UpdateTexture(colorBufferTexture, 
			NULL, 
			colorBuffer, 
			(int)(uint32_t)WINDOW_WIDTH * sizeof(uint32_t)
	);
	SDL_RenderCopy(all->render, colorBufferTexture, NULL, NULL);
}

void	render(t_all *all)
{
	SDL_SetRenderDrawColor(all->render, 0, 0, 0, 255);
	SDL_RenderClear(all->render);
	
	generateProjection(all);

	//clear the color buffer
	renderColorBuffer(all);
	clearColorBuffer(0xFF00EE30);
	
	//display minimap
	renderMap(all);
	renderRays(all);
	renderPlayer(all);
	
	SDL_RenderPresent(all->render);
}

int main()
{
	t_all all;
	
	setup(&all);

	all.isGamingRuning = inicializaçãoJanela(&all);
	init_color(&all);	
	while(all.isGamingRuning)
	{
		processInput(&all);
		update(&all);
		render(&all);
	}
	destroyWindow(&all);
	return 0;
}

