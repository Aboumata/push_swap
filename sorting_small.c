/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:05:10 by aboumata          #+#    #+#             */
/*   Updated: 2025/02/27 15:05:12 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stack)
{
	if ((*stack)->val > (*stack)->next->val)
		swap_stack(stack, 'a');
}

void	sort_3(t_stack **stack)
{
	int	yan;
	int	sin;
	int	krad;

	yan = (*stack)->val;
	sin = (*stack)->next->val;
	krad = (*stack)->next->next->val;
	if (yan > sin && sin < krad && krad > yan)
		swap_stack(stack, 'a');
	else if (yan > sin && sin > krad)
	{
		swap_stack(stack, 'a');
		rev_rotate(stack, 'a');
	}
	else if (yan > sin && sin < krad && yan > krad)
		rotate_stack(stack, 'a');
	else if (yan < sin && sin > krad && yan < krad)
	{
		swap_stack(stack, 'a');
		rotate_stack(stack, 'a');
	}
	else if (yan < sin && sin > krad && yan > krad)
		rev_rotate(stack, 'a');
}

void	sort_4_or_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;

	while (stack_len(*stack_a) > 3)
	{
		smallest = search_smallest(*stack_a);
		while (*stack_a != smallest)
		{
			if (index_val(*stack_a, smallest->val) <= stack_len(*stack_a) / 2)
				rotate_stack(stack_a, 'a');
			else
				rev_rotate(stack_a, 'a');
		}
		push_stack(stack_b, stack_a, 'a');
	}
	sort_3(stack_a);
	while (*stack_b)
		push_stack(stack_a, stack_b, 'b');
}

void sort_small(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		swap_stack(a, 'a');
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_4_or_5(a, b);
}