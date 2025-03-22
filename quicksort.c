#include "push_swap.h"


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

void		quick_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi);
        quick_sort(arr, pi + 1, high);
    }
}
