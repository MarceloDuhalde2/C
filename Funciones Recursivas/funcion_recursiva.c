#include <stdio.h>
#include <stdlib.h>

// funcion recursiva
unsigned mult(unsigned m, unsigned n)
{
	if (n == 1) return m;
    else if ((n & 1) == 0) return mult(m << 1, n >> 1);
    else return mult(m << 1, n >> 1) + m;
	
}

int main(int argc, char **argv)
{
    int m, n;    
    
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    
    if (argc != 3)
    {
        printf("uso: %s num1 num2\n", argv[0]);
        exit(-1);
    }
    
    printf("Numeros ingresados: n1: %d - n2: %d\n", m, n);
    printf("Multiplicación: %d\n", mult(m, n));
    
    return 0;
}
