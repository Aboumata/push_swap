#include "push_swap.h"

int find_value_position(t_stack *stack, int value)
{
    int pos = 0;
    while (stack && stack->val != value) {
        pos++;
        stack = stack->next;
    }
    return pos;
}

static int	*create_sorted_array(t_stack *stack, int size)
{
    int		*arr;
    t_stack	*current;
    int		i;

    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);
    current = stack;
    i = -1;
    while (++i < size && current)
    {
        arr[i] = current->val;
        current = current->next;
    }
    quicksort(arr, 0, size - 1);
    return (arr);
}

static void	push_range(t_stack **a, t_stack **b, int *tab, int *range)
{
    int	start;
    int	end;

    start = range[0];
    end = range[1];
    while (*a)
    {
        if ((*a)->val >= tab[start] && (*a)->val <= tab[end])
        {
            push_stack(b, a, 'a');
            start++;
            end = (end + 1 < range[2]) ? end + 1 : range[2] - 1;
        }
        else if ((*a)->val < tab[start])
        {
            push_stack(b, a, 'a');
            rotate_stack(b, 'b');
            start++;
            end = (end + 1 < range[2]) ? end + 1 : range[2] - 1;
        }
        else
            rotate_stack(a, 'a');
    }
}

static void	optimized_pushback(t_stack **a, t_stack **b, int size)
{
    int	max_val;
    int	max_index;

    while (*b)
    {
        max_val = find_max_value(*b);
        max_index = find_value_position(*b, max_val);
        if (max_index <= stack_len(*b) / 2)
            while ((*b)->val != max_val)
                rotate_stack(b, 'b');
        else
            while ((*b)->val != max_val)
                rev_rotate(b, 'b');
        push_stack(a, b, 'b');
        if (stack_len(*a) == size)
            break ;
    }
}

void	sort(t_stack **a, t_stack **b, int size)
{
    int	*tab;
    int	range[3];

    tab = create_sorted_array(*a, size);
    if (!tab)
        return;
    range[0] = 0;
    range[1] = (size > 100) ? size / 11 : size / 5;
    range[2] = size;
    push_range(a, b, tab, range);
    optimized_pushback(a, b, size);
    free(tab);
}