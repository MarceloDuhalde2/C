#include <stdio.h>
#include <math.h>
typedef double (*PFUNC)(double);
int main()
{
	PFUNC pf;
	pf = sin; // pf apunta a donde está la funcion seno
	printf("%f\n", pf(M_PI));
	pf = cos;
	printf("%f\n", pf(M_PI));
	pf = exp;
	printf("%f\n", pf(M_PI));
return 0;
}
