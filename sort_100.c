#include "push_swap.h"

static void	optimized_push_chunks(t_stack **a, t_stack **b, int size)
{
    int	chunk_size = 17;
    int	next_target = chunk_size;
    int	remaining = size;
    int	rotate_count = 0;

    while (remaining > 0)
    {
        if ((*a)->index <= next_target)
        {
            push_stack(b, a, 'a');
            if ((*b)->index < (next_target - (chunk_size / 3)))
                rotate_stack(b, 'b');
            remaining--;
            next_target += (remaining > size * 0.9) ? 0 : 1;
            rotate_count = 0;
        }
        else
        {
            if (rotate_count++ > size / 2)
            {
                rev_rotate(a, 'a');
                rotate_count = 0;
            }
            else
                rotate_stack(a, 'a');
        }
    }
}

void	sort_100(t_stack **a, t_stack **b)
{
    int	*sorted;
    int	size;
    int	max_index;
    int	rot_dir;
    int	rotations;

    size = stack_len(*a);
    sorted = create_sorted_array(*a, size);
    if (!sorted)
        return;
    assign_indexes(*a, sorted, size);
    free(sorted);

    optimized_push_chunks(a, b, size);

    while (*b)
    {
        max_index = find_max_index(*b);
        rot_dir = rotation_direction(*b, max_index);
        rotations = (rot_dir) ? find_position(*b, max_index) :
            stack_len(*b) - find_position(*b, max_index);

        while (rotations-- > 0)
        {
            if (rot_dir)
                rotate_stack(b, 'b');
            else
                rev_rotate(b, 'b');
        }
        push_stack(a, b, 'b');
    }
}
