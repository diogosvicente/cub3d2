#include "all.h"
#include <stdio.h>

const char *textureFileNames[NUM_TEXTURE] = {
	"./images/flu.png",
	"./images/2023.png",
	"./images/taça.png"
};

void loadWallTextures(texture_t *jorginho[])
{
	for (int i = 0; textureFileNames[i]; i++)
	{
		upng_t *upng;
		
		upng = upng_new_from_file(textureFileNames[i]);
		if (upng != NULL){
			upng_decode(upng);
			if(upng_get_error(upng) == UPNG_EOK) {
				jorginho[i]->upngtext = upng;
				printf("%d\n", jorginho[i]->width = upng_get_width(upng));
				printf("%d\n", jorginho[i]->height = upng_get_height(upng));
				jorginho[i]->texture_buffer = (uint32_t *)upng_get_buffer(upng);
			}
			else
			{
				printf("porra nao achou nada aqui paizao\n");
				exit(1);
			}
		}
		else
		{
			printf("porra nao achou nada");
			exit(1);
		}
	}
}

void	freewall(texture_t *jorginho[])
{
	for (int i = 0; i < NUM_TEXTURE; i++)
	{
		upng_free(jorginho[i]->upngtext);
	}
}
