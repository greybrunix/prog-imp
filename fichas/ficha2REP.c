#include <stdio.h>
#include <stdlib.h>

/* exercicio 1 recursividade explicita*/
float multInt1 (int n, float m)
{
 if (n == 1) return m;
 return (m + multInt1(n-1, m));
}

/* exercicio 1 iterativo */
float multInt2 (int n, float m)
{
 int r = 0;
 for (n; n > 0; n--)
   r += m;
 return r;
}
/* exercicio 2*/
float multInt3 (int n, float m)
{
 float c = 0;
 while (n > 0)
 {
  if (n % 2) c += m;
  n /= 2; m *= 2;
 }
 return c;
}
/* exercicio 4 */
int mdc2 (int a, int b)
{
 if (a == b) return a;
 if (a > b) return mdc2(a-b,b);
 return mdc2(a,b-a);
}
/* exercicio 6*/
int fib1 (int n)
{
 if (n < 3) return 1;
 return (fib1(n-1) + fib1(n-2));
}
/* exercicio 6b*/
int fib2(int n)
{
 int a=1, b, z;
 for(n; n > 1; n--)
 {
  b = a;
  z = a + b;
  a = z;
 }
 return a;
}

int main()
{
 printf("[10,20]: %d\n", mdc2(10,20));
 printf("5x3: %.5f\n", multInt3(5,3.0));
 printf("fib2 pos 3: %d\n", fib1(19));
 return 0;
}
