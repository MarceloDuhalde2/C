#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	double *pd;
	pd = malloc(sizeof(*pd));
	*pd = M_PI;
	printf("%f %f\n", *pd, *pd +1);
	free(pd);
	return 0;
}
//Output: ./Prueba2.out
//3.141593 4.141593

