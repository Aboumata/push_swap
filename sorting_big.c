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

void assign_indexes(t_stack *stack) {
	t_stack *cur;
	int *arr;
	int size, i;

	size = stack_len(stack);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return;

	cur = stack;
	i = 0;
	while (cur) {
		arr[i++] = cur->val;
		cur = cur->next;
	}
	quicksort(arr, 0, size - 1);
	cur = stack;
	while (cur) {
		cur->index = binary_search(arr, size, cur->val);
		cur = cur->next;
	}

	free(arr);
}

void chunk_sort(t_stack **a, t_stack **b, int chunk_size)
{
	int chunk_num = (stack_len(*a) + chunk_size - 1) / chunk_size;
	for (int i = 0; i < chunk_num; i++)
	{
		int min = i * chunk_size;
		int max = (i + 1) * chunk_size;
		while (stack_len(*a) > 0)
		{
			if ((*a)->index >= min && (*a)->index < max)
				push_stack(b, a, 'b');
			else
				rotate_stack(a, 'a');
		}
	}
	while (*b)
		push_stack(a, b, 'a');
}

static void process_bit(t_stack **a, t_stack **b, int bit)
{
	int size = stack_len(*a);
	int i = 0;
	while (i++ < size)
	{
		if ((((*a)->index >> bit) & 1) == 0)
			push_stack(b, a, 'b');
		else
			rotate_stack(a, 'a');
	}
}

void radix_sort(t_stack **a, t_stack **b)
{
	int max_bits = 0;
	int max_num = stack_len(*a) - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;

	for (int bit = 0; bit < max_bits; bit++)
	{
		process_bit(a, b, bit);
		while (*b)
			push_stack(a, b, 'a');
	}
}
