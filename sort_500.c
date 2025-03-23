#include "push_swap.h"

#define CHUNK_SIZE 30

static void smart_rotate_a(t_stack **a, int threshold) {
    int pos = 0;
    t_stack *tmp = *a;
    int len = stack_len(*a);

    while (tmp && tmp->index > threshold) {
        pos++;
        tmp = tmp->next;
    }

    if (pos <= len/2) while (pos--) rotate_stack(a, 'a');
    else while (len - pos++ > 0) rev_rotate(a, 'a');
}

static void push_chunks(t_stack **a, t_stack **b, int size) {
    int current_max = CHUNK_SIZE - 1;
    int pushed = 0;

    while (pushed < size) {
        if ((*a)->index <= current_max) {
            push_stack(b, a, 'a');
            if (stack_len(*b) > 1 && (*b)->index < (*b)->next->index)
                rotate_stack(b, 'b');
            pushed++;
            current_max = (pushed + CHUNK_SIZE < size) ? pushed + CHUNK_SIZE : size - 1;
        } else {
            smart_rotate_a(a, current_max);
        }
    }
}

static void optimized_pushback(t_stack **a, t_stack **b) {
    while (*b) {
        int max_pos = find_max_position(*b);
        int len = stack_len(*b);

        if (max_pos <= len/2) while (max_pos--) rotate_stack(b, 'b');
        else while (len - max_pos++ > 0) rev_rotate(b, 'b');

        push_stack(a, b, 'b');
    }
}

void sort_500(t_stack **a, t_stack **b) {
    int size = stack_len(*a);
    int *sorted = create_sorted_array(*a, size);

    assign_indexes(*a, sorted, size);
    push_chunks(a, b, size);
    optimized_pushback(a, b);
    free(sorted);
}
