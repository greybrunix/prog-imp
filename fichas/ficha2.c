#include <stdio.h>

//iteractive implementation
float multInt1 (int n, float m)
{
 int r = 0;
 for (int i = 0; i < n; i++) r += m;
 return r;
}
// recursive implementation (recursivity is important)
float multIntRec (int n, float m)
{
 if (n == 1) return m;
 return (m + multIntRec(n-1,m));
}

int fib1 (int n)
{
 if (n < 2) return 1;
 return (fib1 (n-1) + fib1(n-2));
}

int fib2 (int n) 
{
 int x,y=1,z=1;
 for (int i = 1; i<=n; i++)
 {
  x = z;
  z += y;
  y = x;
 }
 return y;
}

main()
{
 int x;
 scanf("%d", &x);
 printf("this is the thing: %d\n", fib1(x));
 printf("this is the thing: %d\n", fib2(x));
}
