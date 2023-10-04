#include <stdio.h>
#include <stdlib.h>

double	rad2deg(double rad)
{
	double	dg;

	dg = rad * (180.0 / 3.14);
	return (dg);
}

int main(int a, char **b)
{
	double c = 0.0;

	if(a <= 1)
		printf("passa um angulo ai menó\n");
	else
	{
		while(*++b)
		{
			c = atof(*b);
			printf("Angulo em Radiano -> %s\nAngulo em Grau -> %f\n\n", *b, rad2deg(c));
		}
	}
	return 0;
}
