#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _list
{
   int val;
   struct _list * next;
};
struct _tree
{
   int val;
   struct _tree * left, *right;
};
typedef struct _list * list;
typedef struct _tree * tree;

void insert(l, x)
   list * l;
   int x;
{
   list new_node = (list) malloc(sizeof (struct _list));
   new_node->val = x;
   new_node->next = NULL;
   if (*l == NULL)
   {
      *l = new_node;
      goto end;
   }
   list tmp = *l;
   while (tmp->next != NULL)
      tmp = tmp->next;
   tmp->next = new_node;
end:
   return;
}

int procura(a, N, x)
   int a[];
   int N;
   int x;
{
   int res = -1;
   int high= N-1, low= 0, mid;
reset:
   mid = low + (high-low) / 2;
   if (a[mid] == x) {res = mid; goto end;}
   if (a[mid] < x) {low = mid + 1; goto reset;}
   else {high = mid - 1; goto reset;}
end:
   return res;
}
void roda(l)
   list *l;
{
   if (*l == NULL) goto end;
   list tmp = *l;
   list fst = *l;
   list prev = tmp;
   while (tmp != NULL)
   {
      prev = tmp;
      tmp = tmp->next;
   }
   prev->next = fst;
   tmp->next = fst->next;
   fst->next = NULL;
end:
   return;
}

int apaga(t, n)
   int n;
   tree t;
{
   if (t == NULL || n == 0) return 0;
   tree tmp = t;
   free(tmp);
   return 1 + apaga(t->left, n-1) + apaga(t->right, n-2);
}

char itc(x)
   int x;
{
   char c = x + '0';
   return c;
}
void checksum(s)
   char s[];
{
   int i;
   int total = 0, N = strlen(s); int tmp[N];
   for (i = N-1; i >=0; i++)
       tmp[i] += i%2? (s[i]-'0') * 2 : (s[i] - '0');
   // Problem it doesnt register correctly if the double overflows the range of 0-9
   // Don't actually know how to solve this issue, will try later
   for (i = 0; i < N; i++)
      total += tmp[i];
   s[N] = itc(total % 10);
}

// EX 5 not done, dont remember it but it was a simple Dynamic Programming solution

int main(argc, argv)
   const char ** argv;
   int argc;
{
   exit(0);
}
