#include <stdio.h>
// funcion sin punteros
void swap(int i, int j)
{
	int tmp = i;
	
	i = j;
	j = tmp;
}

int main()
{
    int x = 5, y = 7;
    
    printf("%d %d\n", x, y);
    swap(x, y);    
    printf("%d %d\n", x, y);
    
    return 0;
}
