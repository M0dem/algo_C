#include <stdio.h>
#include <stdlib.h>

#include "utility.h"

/*
// Quick Sort
// Nathanael Key
// August 14, 2020
*/

void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort (int* list, int L, int R)
{
    if (R - L <= 0)
        return;

    // pivot is the last element
    int p = R;    
    
    // lesser index
    int j = L;
    for (int i = L; i < p; ++i)
    {
        if (list[i] <= list[p])
        {
            swap(&list[i], &list[j++]);
        }
    }

    swap(&list[p], &list[j]);
    p = j;

    quick_sort(list, L, p - 1);
    quick_sort(list, p + 1, R);
}

int main ()
{
    int len = 15;
    int upper = 50;
    int* list = gen_list(len, upper);

    print_list(list, len);
    quick_sort(list, 0, len - 1);
    print_list(list, len);
    
    free(list);
    return 0;    
}
