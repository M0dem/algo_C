#include <stdio.h>
#include <stdlib.h>

#include "utility.h"

/*
// Merge Sort
// Nathanael Key
// August 13, 2020
*/

void merge (int* list, int L, int m, int R)
{
    int Li = L;
    int Ri = m;

    int len = R - L;
    int* copy = calloc(len, sizeof(int));

    for (int k = 0; k < len; ++k)
    {
        if (Li < m && (Ri >= R || list[Li] <= list[Ri]))
        {
            copy[k] = list[Li++];
        }
        else
        {
            copy[k] = list[Ri++];
        }
    }

    // transcribe our `copy` array onto `list`
    for (int k = 0; k < len; ++k)
        list[k + L] = copy[k];

    free(copy);
}

void merge_sort (int* list, int L, int R)
{
    if (R - L <= 1)
        return;

    int m = (L + R) / 2;
    
    merge_sort(list, L, m);
    merge_sort(list, m, R);
    
    merge(list, L, m, R);
}

int main ()
{
    int* list;
    int n = 15;
    int upper = 50;
    list = gen_list(n, upper);
    
    print_list(list, n);
    merge_sort(list, 0, n);
    print_list(list, n);

    free(list);
    
    return 0;
}
