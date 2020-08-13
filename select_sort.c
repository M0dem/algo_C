#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
// Selection Sort
// Algorithm Implementation
// Nathanael Key
// August 13, 2020
*/

void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void select_sort (int* list, int len)
{
    int min, k;
    for (int i = 0; i < len; ++i)
    {
        min = list[i];
        k = i;
        for (int j = i; j < len; ++j)
        {
            if (list[j] < min)
            {
                min = list[j];
                k = j;
            }
        }
        swap(&list[i], &list[k]);
    }
}

void print_list (int* list, int len)
{
    printf("{");
    for (int i = 0; i < len; ++i)
    {
        printf("%d", list[i]);
        if (i != len - 1)
            printf(", ");
    }
    printf("}\n");
}

int main ()
{
    int len = 15;
    int* list = calloc(len, sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < len; ++i)
        list[i] = rand() % 50;

    print_list(list, len);
    select_sort(list, len);
    print_list(list, len);

    free(list);    
    
    return 0;
}
