#include "defs.h"

//texture_t jorginho[NUM_TEXTURE]; 

/*void init_ray(t_ray **ray)
{
	t_ray *rays = malloc(sizeof(t_ray) * NUM_RAYS);

	*ray = rays;
}*/
void	setup(t_all *all)
{
	all->window = NULL;
	all->render = NULL;
	all->isGamingRuning = FALSE;
	all->ticksLastFrame = 0;
	all->rays = malloc(sizeof(t_ray) * NUM_RAYS);
	init_player(&all->player);
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

void	render(t_all *all)
{
	SDL_SetRenderDrawColor(all->render, 0, 0, 0, 255);
	SDL_RenderClear(all->render);
	
	renderwallProjection(all);

	//clear the color buffer
	//clearColorBuffer(all, 0xFF00EE30);
	renderColorBuffer(all);
	clearColorBuffer(all, 0xFF00EE30);
	//renderwallProjection(all);
	
	//display minimap
	//renderMap(all);
	//renderRays(all);
	//renderPlayer(all);
	
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

