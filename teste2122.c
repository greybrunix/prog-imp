#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/******************* UTILS **************************/
typedef struct _list
{
	int _val;
	struct _list* _next;
}*list; // linked list of integer values

typedef struct _tree
{
	int _val;
	struct _tree *_left, *_right;
}*tree; // Binary search tree

void
insert(l, x)
	list *l;
	int x;
{
	list new_node = (list) malloc(sizeof (struct _list));
	new_node->_val = x;
	new_node->_next = NULL;
	if (*l == NULL)
	{
		*l = new_node;
		return;
	}
	list tmp = *l;
	while (tmp->_next != NULL)
		tmp = tmp->_next;
	tmp->_next = new_node;
} // trivial standard insertion to the end of a linked list


/********************** EX 1 ************************/
void
swap(px, py)
	int * px, *py;
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

void
bubble_sort(v, N)
	int v[], N;
{
	int i,j;
	for (i = 0; i < N-1; i++)
		for (j = 0; j < N-i-1; j++)
			if (v[j] > v[j+1])
				swap(&v[j],&v[j+1]);
}

int
nesimo(v, N,i)
	int v[], N, i;
{
	bubble_sort(v, N);
	return v[i-1];
} // We only need to sort the array and get the element in the index i (-1 for it starts at 0)
	// O(N^2) due to bubble_sort
/*********************** EX 2 ***********************/
list
removeMaiores(l, x)
	list l;
	int x;
{
	if (l == NULL) goto end;
	list tmp = l;
	list prev = tmp;
	list aux = tmp;
	while (tmp->_next != NULL && tmp->_val <= x)
	{
		prev = tmp;
		tmp = tmp->_next;
	}
	if (tmp->_val > x)
	{
		prev->_next = NULL;
		aux = tmp;
		tmp = tmp->_next;
		free(aux);
		while (tmp->_next != NULL)
		{
			aux = tmp;
			tmp = tmp->_next;
			free(aux);
		}
	}
end:
	return l;
} // List is sorted so we only need to find the first element larger than x and free everything from there
	// There are no memory leaks in this code

/********************* EX 3 ****************/
list
caminho(t, x)
tree t; int x;
{
	list l = NULL;
	if (t == NULL) goto end;
	tree tmp = t;
	while (tmp != NULL && tmp->_val != x)
	{
		if (x > tmp->_val)
		{
			insert(&l, tmp->_val);
			tmp = tmp->_right;
		}
		else
		{
			insert(&l, tmp->_val);
			tmp = tmp->_left;
		}
	}
	if (tmp->_val != x) l = NULL;
	else insert(&l, x);
end:
	return l;
} // Preserves the structure of the tree and creates a list with the path to x
/********************** EX4 *****************/
void
inc(s)
	char s[];
{
	int i, x = strlen(s);
	for(i = (x-1); i >= 0; i--)
	{
		if (s[i] == '9') s[i] = '0';
		else
		{
			s[i]++;
			goto end; // Nothing more to study
		}
	}
	if (s[0] == '0')
	{
		s[0] = '1';
		s[x] = '0';
	}
end:
	return;
}
/********************* EX 5 *****************/
// Use memoization or just recursion

/*****************  TESTS *****************/
int
main(argc, argv)
	char**argv;
	int argc;
{
	char number[99] = "99999";

	printf("\t EX 1\n\n");
	int v[10] = {10,9,2,5,8,1,7,2,4,15};
	int x = nesimo(v,10,8);
	printf("%d\n\n", x);

	printf("\t EX 2\n\n");
	list l1 = NULL;
	insert(&l1,10);
	insert(&l1,20);
	insert(&l1,30);
	insert(&l1,60);
	removeMaiores(l1,20);
	printf("%d\n%p\n\n", l1->_val, l1->_next->_next);

	printf("\t EX 3\n\n");
	tree t = NULL;
	//assume this exists, also dont run this, unless you lke
	//memory leaks
	insertTree(&t, 10);
	insertTree(&t, 15);
	printf("Hello");
	insertTree(&t, 5);
	list l2 = caminho(t, 15);
	printf("%d -> %d -> NULL\n", l2->_val, l2->_next->_val);
	// replace with a proper list dump


	printf("\t EX 4\n\n");
	inc(number);
	printf("%s\n\n", number);

	exit(0);
}
