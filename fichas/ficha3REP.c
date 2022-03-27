#include <stdio.h>
#include <stdlib.h>
/* 1a
 * Output = 1 1 4 
 *          2 2 6
 *          3 3 8
 *          4 4 10
 *          5 5 12
*/
/* 1b
 * Output = 13
*/

void swapM(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap(int v[], int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
int soma (int v[], int N)
{
    int r = 0;
    for (int i = 0; i < N; i++) r += v[i];
    return r;
}
int main()
{
    int x = 3, y = 5;
    int arr[5] = {1,2,3,4,5};
    swapM(&x, &y);
    swap(arr, 2,3);
    int s = soma(arr, 5);
    printf("%d\n", s);
    return 0;
}
