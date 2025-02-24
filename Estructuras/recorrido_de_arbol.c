#include <stdio.h>
#include <stdlib.h>
typedef struct A{
	int n;
	struct A *i, *d;
} *Arbol;

Arbol inserta(int n, Arbol a)
{
	if (a == NULL){
	a = malloc(sizeof(*a));
	a -> n = n;
	a -> i= a-> d = NULL;
	}
	else if (n< a->n) a-> i = inserta(n, a->i);
	else if (n> a->n) a-> d = inserta(n, a->d);
	return a;
}

void recorre(Arbol a)
{
if (a!= NULL){
	recorre(a->i);
	printf("%d ", a->n);
	recorre(a->d);
	}
}
int main()
{
	Arbol a = NULL;
	int i;
	for (i=0; i<500; i++)
		a = inserta(random()%1000, a);
	recorre(a);
	return 0;
}
