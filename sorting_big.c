/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:41:58 by aboumata          #+#    #+#             */
/*   Updated: 2025/03/02 10:42:09 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_chunks(t_stack **a, t_stack **b, int size, int chunks)
{
    int min, max;
    int chunk_size = size / chunks;
    int i = 0;

    while (i < chunks)
    {
        min = i * chunk_size;
        max = (i + 1) * chunk_size;
        int count = stack_len(*a);

        while (count--)
        {
            if ((*a)->index >= min && (*a)->index < max)
                push_stack(b, a, 'b');
            else if (count > 0)
                rotate_stack(a, 'a');
        }
        i++;
    }
}

static void radix_sort(t_stack **a, t_stack **b, int size)
{
    int max_index = size - 1;
    int max_bits = 0;
    int bit = 0;

    while ((max_index >> max_bits) != 0)
        max_bits++;

    while (bit < max_bits)
    {
        int count = size;
        while (count--)
        {
            if ((((*a)->index >> bit) & 1) == 0)
                push_stack(b, a, 'b');
            else
                rotate_stack(a, 'a');
        }
        while (*b)
            push_stack(a, b, 'a');
        bit++;
    }
}

void sort_big(t_stack **a, t_stack **b)
{
    int size = stack_len(*a);
    if (size <= 3)
    {
        sort_3(a);
        return;
    }
    push_chunks(a, b, size, 5);
    radix_sort(a, b, size);
}

