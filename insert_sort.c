#include <stdio.h>
#include <stdlib.h>

#include "utility.h"

void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert_sort (int* list, int len)
{
    int n;
    for (int i = 1; i < len; ++i)
    {
        if (list[i] < list[i - 1])
        {
            for (int k = i; k > 0; --k)
            {
                swap(&list[k], &list[k - 1]);
                if (k - 1 == 0 || list[k - 1] > list[k - 2])
                    break;
            }
        }
    }
}

int main ()
{
    int len = 8;
    int upper = 20;
    int* list = gen_list(len, upper);

    print_list(list, len);
    insert_sort(list, len);
    print_list(list, len);

    free(list);

    return 0;    
}
