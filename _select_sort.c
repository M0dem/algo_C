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


