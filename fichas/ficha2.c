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

// this is the same as it is in the exercise sheet, just converted to C
int fib1 (int n)
{
 if (n < 2) return 1;
 return (fib1 (n-1) + fib1(n-2));
}

// a bit more complex but all fibonaci algorithms are the same
int fib2 (int n) 
{
 int x,y=1,z=1;
 for (int i = 1; i<=n; i++) // < 2 etcetc
 {
  x = z;
  z += y;
  y = x; // switching and swapping mumbo jumbo 
 }
 return y;
}

main()
{
 int x;
 scanf("%d", &x);
 printf("this is the thing: %d\n", fib1(x));
 printf("this is the thing: %d\n", fib2(x));
 /* note that the fibonnaci seq is as follows in an array:
 [1][1][2][3][5][8][13][21]
 */
}
