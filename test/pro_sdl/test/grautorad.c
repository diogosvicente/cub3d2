#include <stdio.h>
#include <stdlib.h>

double	deg2rad(double dg)
{
	double	rad;

	rad = dg * (3.14 / 180.0);
	return (rad);
}

int main(int a, char **b)
{
	double c = 0.0, d = 0.0;

	if(a <= 1)
		printf("passa um angulo ai menó\n");
	else
	{
		c = deg2rad(atof(b[1]));
		printf("%f\n", c);
	}
	return 0;
}
