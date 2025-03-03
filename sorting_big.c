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

void	index_num(t_stack *stack)
{
	int		index;
	int		len;
	t_stack	*current;
	t_stack	*smallest;

	index = 0;
	len = stack_len(stack);
	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		current->index = -1;
		current = current->next;
	}
	while (index < len)
	{
		smallest = NULL;
		current = stack;
		while (current)
		{
			if (current->index == -1 && (!smallest
					|| current->val < smallest->val))
				smallest = current;
			current = current->next;
		}
		if (smallest)
			smallest->index = index++;
	}
}

int	max_bits(t_stack *stack)
{
	int	max_bits;
	int	size;

	if (!stack)
		return (0);
	size = stack_len(stack);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

void	push_bits(t_stack **stack_a, t_stack **stack_b, int bit)
{
	int		size;
	int		i;
	t_stack	*now;

	if (!stack_a || !*stack_a)
		return ;
	size = stack_len(*stack_a);
	i = 0;
	while (i < size)
	{
		now = *stack_a;
		if (((now->index >> bit) & 1) == 0)
			push_stack(stack_b, stack_a);
		else
			rotate_stack(stack_a);
		i++;
	}
	while (*stack_b)
		push_stack(stack_a, stack_b);
}

void	radix_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	end_bits;
	int	i;

	if (!stack_a || !*stack_a)
		return ;
	index_num(*stack_a);
	end_bits = max_bits(*stack_a);
	i = 0;
	while (i < end_bits)
	{
		push_bits(stack_a, stack_b, i);
		i++;
	}
}
