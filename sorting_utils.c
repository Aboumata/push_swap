#include "push_swap.h"

void swap_int(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int find_max_value(t_stack *stack)
{
    int max = INT_MIN;
    while (stack) {
        if (stack->val > max)
            max = stack->val;
        stack = stack->next;
    }
    return max;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
