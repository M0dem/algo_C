#include <stdio.h>
#include <stdlib.h>

#include "utility.h"

void swap (int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert_sort (int *list, int n)
{
	int p;
	for (int i = 1; i < n; ++i) {
		p = i;
		for (int j = p - 1; list[p] < list[j] && j >= 0; --j) {
			swap(&list[p--], &list[j]);
		}
	}
}

int main ()
{
	int n = 15;
	int upper = 50;
	int *list = gen_list(n, upper);

	print_list(list, n);
	insert_sort(list, n);
	print_list(list, n);

	free(list);
	return 0;
}
