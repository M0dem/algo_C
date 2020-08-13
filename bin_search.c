#include <stdio.h>
#include <stdlib.h>

#include "_select_sort.h"
#include "utility.h"

int bin_search (int* A, int n, int T)
{
    int L = 0;
    int R = n - 1;
    int m;

    while (L <= R)
    {
        m = (L + R) / 2;
        if (A[m] < T)
            L = m + 1;
        else if (A[m] > T)
            R = m - 1;
        else
            return m;
    }

    return -1;
}

int main ()
{
    int len = 15;
    int upper = 50;
    int* list = gen_list(len, upper);
        
    print_list(list, len);
    select_sort(list, len);
    print_list(list, len);

    int target = 33;
    int i = bin_search(list, len, target);
    printf("\tlist[%d] = %d\n", i, target);
    
    free(list);
    return 0;    
}
