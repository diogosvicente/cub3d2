#include "defs.h"

//uint32_t *all->colorBuffer = NULL;
static SDL_Texture *colorBufferTexture;
//uint32_t *all->wallTexture = NULL;
//uint32_t *textures[NUM_TEXTURE];

void	init_color(t_all *all)
{
	all->colorBuffer = (uint32_t *)malloc(sizeof(uint32_t) * (uint32_t)WINDOW_WIDTH * (uint32_t)WINDOW_HEIGHT);
	colorBufferTexture = SDL_CreateTexture(
			all->render, 
			SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING,
			WINDOW_WIDTH, 
			WINDOW_HEIGHT
	);
	all->wallTexture = (uint32_t *)malloc(sizeof(uint32_t) * (uint32_t)TEXTURE_WIDTH * (uint32_t)TEXTURE_HEIGHT);
	//load texture
	for(int x = 0; x < TEXTURE_WIDTH; x++)
	{
		for(int y = 0; y < TEXTURE_HEIGHT; y++)
		{
			/*if (x % 8 && y % 8)
				all->wallTexture[(TEXTURE_WIDTH * y) + x] = 0xFFFFFFFF;
			else
				all->wallTexture[(TEXTURE_WIDTH * y) + x] = 0x00000000;*/
			all->wallTexture[(TEXTURE_WIDTH * y) + x] = 0xFFFFFFFF;

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
	free(all->colorBuffer);
	SDL_DestroyTexture(colorBufferTexture);
	SDL_DestroyRenderer(all->render);
	SDL_DestroyWindow(all->window);
	SDL_Quit();
}

void	clearColorBuffer(t_all *all, uint32_t color)
{
	for(int x = 0; x < WINDOW_WIDTH; x++)
	{
		for(int y = 0; y < WINDOW_HEIGHT; y++)
		{
			if(y >= WINDOW_HEIGHT / 2)
				all->colorBuffer[(WINDOW_WIDTH * y) + x] = color;
			else
				all->colorBuffer[(WINDOW_WIDTH * y) + x] = 0xFFFF0000;
		}
	}
}

void	renderColorBuffer(t_all *all)
{
	SDL_UpdateTexture(colorBufferTexture, 
			NULL, 
			all->colorBuffer, 
			(int)(uint32_t)WINDOW_WIDTH * sizeof(uint32_t)
	);
	SDL_RenderCopy(all->render, colorBufferTexture, NULL, NULL);
}

void	drawpixel(t_all *all, int x, int y, uint32_t color)
{
	all->colorBuffer[(WINDOW_WIDTH * y) + x] = color;
}

void	drawRect(t_all *all, int x, int y, int width, int height, uint32_t color)
{
	for(int i = x; i <= (x + width); i++)
	{
		for(int j = y; j <= (y + height); j++){
			drawpixel(all, i, j, color);
		}
	}
}

void	drawline(t_all *all, int x0, int x1, int y0, int y1, uint32_t color)
{
	int deltax = (x1 - x0);
	int deltay = (y1 - y0); 

	int sideleght = (abs(deltax) >= abs(deltay)) ? abs(deltax) : abs(deltay);

	float xincrement = deltax / (float)sideleght;
	float yincrement = deltay / (float)sideleght;

	float currentx = x0;
	float currenty = y0;

	for(int i = 0; i < sideleght; i++)
	{
		drawpixel(all, round(currentx), round(currenty), color);
		currentx += xincrement;
		currenty += yincrement;
	}

}
