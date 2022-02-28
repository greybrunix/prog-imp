#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void swapM (int *x, int *y) // see page 95-96 of C programming language 2nd edition for
{                           // an explaination
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
} // Linear complexity O(N)

void inverteArray(int v[],  int N)
{
 int start = 0, end = N-1;
 while (start < end) swap(v, start++, end--);
} // note the linear time complexity O(N)

void inverteArrayPointer(int v[], int N)
{
 int start = 0, end = N-1;
 while (start < end) swapM(&v[start++], &v[end--]);
} // this is the same function as before, O(N)

int maximum(int v[], int N, int *m)
{
 if (N == 0) return 1;
 *m = INT_MIN;
 for (int i = 0; i < N; i++)
 {
  if (v[i] > *m) *m = v[i];
 }
 return 0;
} // O(N)

int maximumOrd(int v[], int N, int *m)
{
 if (N == 0) return 1;
 *m = INT_MIN;
 for (int i = 0; i < N; i++) if (&v[i] > m) *m = v[i];
 return 0;
} // O(1)

void a_dump(int array[], int N)
{
 for (int i = 0; i < N; i++) printf("%d ", array[i]);
 putchar('\n');
} // O(N)


main()
{
 int v1[5] = {1,2,4,3,5};
 int m;
 // exercise 2
 //int x = 3, y = 5;
 //swapM (&x, &y);
 //printf("%d %d\n",x,y);
 //
 //exercise 3
 //swap(v1, 2, 3);
 printf("%d %d\n", v1[2],v1[3]);
 // exercise 4
 //printf("%d\n", soma(v1, sizeof(v1)/sizeof(v1[0])));
 //exercise 5
 //inverteArrayPointer (v1, sizeof(v1)/sizeof(v1[0]));
 // inverteArray (v1, sizeof(v1)/sizeof(v1[0]));
 a_dump(v1, sizeof(v1)/sizeof(v1[0]));
 //exercise 6
 maximum(v1, sizeof(v1)/sizeof(v1[0]), &m);
 //maximumOrd only works in sorted arrays
 printf("%i\n", m);
 return 0;
} 
