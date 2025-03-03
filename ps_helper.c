/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:04:20 by aboumata          #+#    #+#             */
/*   Updated: 2025/02/27 15:04:22 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	index_val(t_stack *stack, int val)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->val == val)
			return (index);
		index++;
		stack = stack->next;
	}
	return (index);
}

t_stack	*search_smallest(t_stack *stack)
{
	t_stack	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->val < smallest->val)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->val > stack->next->val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	stack_add_back(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->val = value;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}
