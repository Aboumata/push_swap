#include "push_swap.h"

int find_min_index(t_stack *stack)
{
    int min;

    if (!stack)
        return (-1);
    min = stack->index;
    while (stack)
    {
        if (stack->index < min)
            min = stack->index;
        stack = stack->next;
    }
    return (min);
}

int find_insert_position(t_stack *b, int index)
{
    int pos = 0;
    t_stack *tmp = b;
    int prev_index = INT_MAX;

    while (tmp)
    {
        if (index > tmp->index && prev_index >= index)
            return (pos);
        prev_index = tmp->index;
        pos++;
        tmp = tmp->next;
    }
    return (0);
}

void optimize_stack_b(t_stack **b, int *sorted, int size) {
    if (!*b || !(*b)->next) return;

    int current_val = (*b)->val;
    int target_pos = 0;

    for (int i = 0; i < size; i++) {
        if (sorted[i] == current_val) {
            target_pos = i;
            break;
        }
    }

    if (target_pos > 0 && (*b)->next->val != sorted[target_pos - 1])
        rotate_stack(b, 'b');
}

void smart_rotate_to_value(t_stack **a, int min_val, int max_val) {
    int forward = 0;
    t_stack *tmp = *a;

    while (tmp && (tmp->val < min_val || tmp->val > max_val)) {
        forward++;
        tmp = tmp->next;
    }

    int backward = stack_len(*a) - forward;
    if (forward <= backward)
        while (forward--)
            rotate_stack(a, 'a');
    else while (backward--)
        rev_rotate(a, 'a');
}

void rotate_to_position(t_stack **stack, int pos, char name)
{
    int len = stack_len(*stack);

    if (pos <= len / 2)
    {
        while (pos-- > 0)
            rotate_stack(stack, name);
    }
    else
    {
        pos = len - pos;
        while (pos-- > 0)
            rev_rotate(stack, name);
    }
}

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

int find_max_index(t_stack *stack) {
    int max = INT_MIN;
    while (stack) {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    return max;
}

int find_position_below_threshold(t_stack *a, int threshold)
{
    int pos = 0;
    while (a) {
        if (a->index <= threshold) return pos;
        pos++;
        a = a->next;
    }
    return -1;
}

int find_max_position(t_stack *b) {
    int max_pos = 0;
    int curr_pos = 0;
    int max_index = -1;

    while (b) {
        if (b->index > max_index) {
            max_index = b->index;
            max_pos = curr_pos;
        }
        curr_pos++;
        b = b->next;
    }
    return max_pos;
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

int find_closest_in_range(t_stack *a, int min_val, int max_val) {
    int forward = 0;
    t_stack *tmp = a;

    while (tmp && (tmp->val < min_val || tmp->val > max_val)) {
        forward++;
        tmp = tmp->next;
    }
    if (!tmp) return -1;

    int len = stack_len(a);
    int backward = len - forward;

    return (forward <= backward) ? forward : backward;
}

void rotate_to_pos(t_stack **stack, int pos, char name) {
    int len = stack_len(*stack);

    if (pos <= len / 2)
        while (pos-- > 0) rotate_stack(stack, name);
    else
        while (len - pos++ > 0) rev_rotate(stack, name);
}

void insert_smartly(t_stack **b) {
    if (!*b || !(*b)->next) return;

    int current_val = (*b)->val;
    int rotations = 0;
    t_stack *tmp = (*b)->next;

    while (tmp && current_val < tmp->val) {
        rotations++;
        tmp = tmp->next;
    }

    if (rotations > 0) {
        int len = stack_len(*b);
        if (rotations <= len / 2)
            while (rotations--) rotate_stack(b, 'b');
        else
            while (rotations++ < len) rev_rotate(b, 'b');
    }
}

int find_in_range(t_stack *a, int min_val, int max_val) {
    int pos = 0;
    t_stack *tmp = a;

    while (tmp) {
        if (tmp->val >= min_val && tmp->val <= max_val)
            return pos;
        pos++;
        tmp = tmp->next;
    }
    return -1;
}