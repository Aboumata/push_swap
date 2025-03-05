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

static void	assign_indexes(t_stack *stack, int len)
{
	int		*values;
	t_stack	*current;
	int		i;

	values = (int *)malloc(len * sizeof(int));
	current = stack;
	i = 0;
	while (current)
	{
		values[i++] = current->val;
		current = current->next;
	}
	quicksort(values, 0, len - 1);
	current = stack;
	while (current)
	{
		current->index = binary_search(values, len, current->val);
		current = current->next;
	}
	free(values);
}

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

static void	process_bit(t_stack **src, t_stack **dst, int bit, char stack_name)
{
	int	size;
	int	i;

	size = stack_len(*src);
	i = 0;
	while (i < size)
	{
		if ((((*src)->index >> bit) & 1) == 0)
		{
			if (stack_name == 'a')
				push_stack(dst, src, 'b');
			else
				push_stack(dst, src, 'a');
		}
		else
			rev_rotate(src, stack_name);
		i++;
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	max_bits;
	int	bit;

	max_bits = get_max_bits(stack_len(*a));
	bit = 0;
	assign_indexes(*a, stack_len(*a));
	while (bit < max_bits)
	{
		if (bit % 2 == 0)
			process_bit(a, b, bit, 'a');
		else
			process_bit(b, a, bit, 'b');
		bit++;
	}
	if (max_bits % 2 == 0)
	{
		while (*b)
			push_stack(a, b, 'a');
	}
}
