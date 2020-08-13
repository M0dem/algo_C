#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// generate a randomly sorted list
// with elements of defined `variance`
int* gen_list (int len, int variance)
{
    int* list = calloc(len, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < len; ++i)
        list[i] = rand() % variance;

    return list;
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
