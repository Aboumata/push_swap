#include "push_swap.h"

void    check_end(int *start, int *end, int len)
{
    (*start)++;
    (*end)++;
    if (*end >= len)
        *end = len - 1;
}

int get_max(t_stack *stack)
{
    int max_val = stack->val;
    while (stack)
    {
        if (stack->val > max_val)
            max_val = stack->val;
        stack = stack->next;
    }
    return max_val;
}

int find_max_index(t_stack *stack, int max_val)
{
    int index = 0;
    while (stack)
    {
        if (stack->val == max_val)
            return index;
        stack = stack->next;
        index++;
    }
    return -1;
}

void    sort_sa(t_stack **sa, t_stack **sb, int *tab, int len)
{
    int    start = 0;
    int    end = (len > 5 && len <= 100) ? len / 6 : 35;

    while (*sa)
    {
        if ((*sa)->val >= tab[start] && (*sa)->val <= tab[end])
        {
            push_stack(sb, sa, 'a');
            check_end(&start, &end, len);
        }
        else if ((*sa)->val < tab[start])
        {
            push_stack(sb, sa, 'a');
            rotate_stack(sb, 'b');
            check_end(&start, &end, len);
        }
        else
            rotate_stack(sa, 'a');
    }
}

void    sort_sb(t_stack **sa, t_stack **sb)
{
    int    max_val;
    int    middle;
    int    max_index;

    while (*sb)
    {
        max_val = get_max(*sb);
        middle = stack_len(*sb) / 2;
        max_index = find_max_index(*sb, max_val);

        if (max_index <= middle)
        {
            while ((*sb)->val != max_val)
                rotate_stack(sb, 'b');
        }
        else
        {
            while ((*sb)->val != max_val)
                rev_rotate(sb, 'b');
        }
        push_stack(sa, sb, 'b');
    }
}

void    sort(t_stack **sa, t_stack **sb, int *tab, int len)
{
    sort_sa(sa, sb, tab, len);
    sort_sb(sa, sb);
}
