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

void	sort_sin(t_stack **stack)
{
	if ((*stack)->val > (*stack)->next->val)
		swap_stack(stack);
}

void	sort_krad(t_stack **stack)
{
	int	yan;
	int	sin;
	int	krad;

	yan = (*stack)->val;
	sin = (*stack)->next->val;
	krad = (*stack)->next->next->val;
	if (yan > sin && sin < krad && krad > yan)
		swap_stack(stack);
	else if (yan > sin && sin > krad)
	{
		swap_stack(stack);
		rev_rotate(stack);
	}
	else if (yan > sin && sin < krad && yan > krad)
		rotate_stack(stack);
	else if (yan < sin && sin > krad && yan < krad)
	{
		swap_stack(stack);
		rotate_stack(stack);
	}
	else if (yan < sin && sin > krad && yan > krad)
		rev_rotate(stack);
}

void	sort_koz_smous(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;

	while (stack_len(*stack_a) > 3)
	{
		smallest = search_smallest(*stack_a);
		while (*stack_a != smallest)
		{
			if (index_val(*stack_a, smallest->val) <= stack_len(*stack_a) / 2)
				rotate_stack(stack_a);
			else
				rev_rotate(stack_a);
		}
		push_stack(stack_b, stack_a);
	}
	sort_krad(stack_a);
	while (*stack_b)
	{
		push_stack(stack_a, stack_b);
		if ((*stack_a)->next && (*stack_a)->val > (*stack_a)->next->val)
			rotate_stack(stack_a);
	}
	if (!is_sorted(*stack_a))
		rotate_stack(stack_a);
}
