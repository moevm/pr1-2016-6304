#include <stdio.h>
#include <stdlib.h>

//Vozvedenie chisla v stepen 1 - 1 

int main () {
int a,b;
int k = 1;
int i;
scanf ("%i %i",&a, &b);


if (b>0)
for (i = 0; i<b; i++)
k = k*a;

if (b<0)
for (i = 0; i<b; i++)
k = k / a;

printf ("%d\n", k);


return 0;
}
