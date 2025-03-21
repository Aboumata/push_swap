#include "push_swap.h"

static void	push_chunks_500(t_stack **a, t_stack **b, int size)
{
    int	chunk_size = 33;
    int	next_target = chunk_size;
    int	remaining = size;
    int	rotate_count = 0;

    while (remaining > 0)
    {
        if ((*a)->index < next_target)
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

static void	move_max_to_top_500(t_stack **b)
{
    int	max_index = find_max_index(*b);
    int	rot_dir, rotations;

    if (max_index == -1)
        return;

    rotations = find_position(*b, max_index);
    if (rotations == -1)
        return;

    rot_dir = rotation_direction(*b, max_index);
    while (rotations-- > 0)
    {
        if (!(*b))
            break;
        if (rot_dir)
            rotate_stack(b, 'b');
        else
            rev_rotate(b, 'b');
    }
}

void	sort_500(t_stack **a, t_stack **b)
{
    int	size = stack_len(*a);
    int	*sorted = create_sorted_array(*a, size);

    assign_indexes(*a, sorted, size);
    free(sorted);

    push_chunks_500(a, b, size);

    while (*b)
    {
        move_max_to_top_500(b);
        push_stack(a, b, 'b');
    }
}
