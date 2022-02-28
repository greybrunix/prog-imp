#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapM (int *x, int *y) // see page 95 of C programming language 2nd edition
{
 int temp = *y;
 *y = *x;
 *x = temp;
}

void swap (int v[], int i, int j) // an array already functions like a pointer
{
 int temp = v[i];
 v[i] = v[j];
 v[j] = temp;
}

int soma (int v[], int N) 
{
 int i, r = 0;
 for (i = 0; i < N; i++) r += v[i];
 return r;
}

main()
{
 int v1[5] = {1,2,4,3,5};
 // exercise 2
 //int x = 3, y = 5;
 //swapM (&x, &y);
 //printf("%d %d\n",x,y);
 //
 //exercise 3
 swap(v1, 2, 3);
 printf("%d %d\n", v1[2],v1[3]);
 // exercise 4
 printf("%d\n", soma(v1, sizeof(v1)/sizeof(v1[0])));
 return 0;
} 
