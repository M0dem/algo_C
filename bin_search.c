#include <stdio.h>
#include <stdlib.h>

#include "_select_sort.h"
#include "utility.h"

int bin_search (int element, int* list, int low, int high)
{
    int mid;
    while (1)
    {
        mid = (high - low) / 2;
        if (list[mid] == element)
            return mid;
        else if (list[mid] > element)
            high = mid - 1;
        else if (list[mid] < element)
            low = mid + 1;
    }
}

int _bin_search (int element, int* list, int low, int high)
{
    int mid = (high - low) / 2;
    if (list[mid] == element)
        return mid;
    else if (list[mid] > element)
        return bin_search(element, list, low, mid - 1);
    else if (list[mid] < element)
        return bin_search(element, list, mid + 1, high);
    else
        printf("wut?!\n");

    return -1;
}

int main ()
{
    int len = 15;
    int* list = gen_list(len, 50);
    
    print_list(list, len);
    select_sort(list, len);
    print_list(list, len);

    int i = bin_search(25, list, 0, len);
    printf("\t%d\n", i);
    
    free(list);
    return 0;    
}
