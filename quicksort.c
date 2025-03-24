#include "push_swap.h"

static void swap_values(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int	partition(int *arr, int low, int high)
{
    int	pivot = arr[(low + high) / 2];
    int	i = low - 1;
    int	j = high + 1;

    while (1)
    {
        while (arr[++i] < pivot) {}
        while (arr[--j] > pivot) {}
        if (i >= j) return (j);
        swap_values(&arr[i], &arr[j]);
    }
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
