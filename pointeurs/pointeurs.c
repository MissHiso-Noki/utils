#include <stdio.h>

int main (void)
{
int a;
int *p;
int **pp;

void *r;
int *pr;

a = 10;
p = &a;
pp = &p;

r = &a;
pr = r;

printf("a = %d\n", a);
printf("contenu de p passant par a = %d\n", *p);
printf("contenu de pp passant par p et a = %d\n\n", **pp);

printf("l'adresse de a = %p\n", &a);
printf("l'adresse de p = %p\n", &p);
printf("l'adresse de pp = %p\n\n", &pp);

printf("l'adresse contenu dans p (adresse de a) = %p\n", p);
printf("l'adresse contenu dans pp (adresse de p) = %p\n\n", pp);

printf("contenu de pr passant par void r puis a = %d\n", *pr);
printf("contenu void r passant par a = %d\n", *(int*)r); //caste le void en ind pour que cela fonctionne
return (0);
}