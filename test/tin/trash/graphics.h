#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>
#include "defs.h"

int	inicializaçãoJanela(t_all *all);
void	destroyWindow(t_all *all);
void	clearColorBuffer(uint32_t color);
void	renderColorBuffer(t_all *all);
void	drawpixel(int x, int y, uint32_t color);
void	drawline(int x0, int x1, int y0, int y1, uint32_t color);

#endif
