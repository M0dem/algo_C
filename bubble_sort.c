#include <stdio.h>
#include <stdlib.h>

#include "utility.h"

/*
// Bubble Sort
// Nathanael Key
// August 14, 2020
*/

void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort (int* list, int len)
{
    int no_sort = 0;
    while (!no_sort)
    {
        no_sort = 1;
        for (int i = 0; i < len - 1; ++i)
        {
            if (list[i] > list[i + 1])
            {
                swap(&list[i], &list[i + 1]);
                no_sort = 0;
            }
        }
    }
}

int main ()
{
    int len = 15;
    int upper = 50;
    int* list = gen_list(len, upper);

    print_list(list, len);
    bubble_sort(list, len);
    print_list(list, len);

    free(list);
    return 0;
}
