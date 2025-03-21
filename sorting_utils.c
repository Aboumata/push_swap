#include "push_swap.h"

int	find_future_rotate(t_stack *a, int threshold)
{
    int	pos;
    int	len;

    pos = 0;
    len = stack_len(a);
    while (a && a->index > threshold)
    {
        pos++;
        a = a->next;
    }
    return (pos <= len / 2) ? pos : len - pos;
}

int	rotation_direction(t_stack *b, int max_index)
{
    int	pos;
    int	len;

    pos = 0;
    len = stack_len(b);
    while (b && b->index != max_index)
    {
        pos++;
        b = b->next;
    }
    return (pos <= len / 2);
}

int	find_max_index(t_stack *stack)
{
    int	max;

    if (!stack)
        return (-1);
    max = stack->index;
    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return (max);
}

int	find_rotations_to_max(t_stack *stack, int max_index)
{
    int	position;
    int	len;

    position = 0;
    len = stack_len(stack);
    while (stack && stack->index != max_index)
    {
        position++;
        stack = stack->next;
    }
    return (position <= len / 2) ? position : len - position;
}

int	find_position(t_stack *stack, int target_index)
{
    int	pos = 0;

    while (stack)
    {
        if (stack->index == target_index)
            return (pos);
        pos++;
        stack = stack->next;
    }
    return (-1);
}

void	swap_values(int *a, int *b)
{
    int	tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int	*create_sorted_array(t_stack *stack, int size)
{
    int		*arr;
    t_stack	*tmp;
    int		i;
    int		j;

    arr = malloc(size * sizeof(int));
    if (!arr)
        return (NULL);
    tmp = stack;
    i = -1;
    while (++i < size)
    {
        arr[i] = tmp->val;
        tmp = tmp->next;
    }
    i = -1;
    while (++i < size)
    {
        j = i;
        while (++j < size)
            if (arr[i] > arr[j])
                swap_values(&arr[i], &arr[j]);
    }
    return (arr);
}

void	assign_indexes(t_stack *stack, int *sorted, int size)
{
    t_stack	*current;
    int		i;

    current = stack;
    while (current)
    {
        i = -1;
        while (++i < size)
        {
            if (current->val == sorted[i])
            {
                current->index = i;
                break ;
            }
        }
        current = current->next;
    }
}