#include  <stdio.h>

void swap(int v[], int i, int j);

void bSort(int v[], int N);

void printAr(int v[], int n)
{
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    putchar('\n');
}

int main()
{
    int v[5] = {5,4,3,2,1};
    printAr(v, 5);
    bSort(v, 5);
    printAr(v,5);
    return 0;
}

void swap(int v[],int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void bSort(int v[], int N)
{
    for (int i = 0; i < N-1; i++)
        for (int j = 0; j < N - i - 1; j++)  if (v[j] > v[j+1]) swap(v, j, j+1);
}
