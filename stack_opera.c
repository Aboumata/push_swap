/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:05:34 by aboumata          #+#    #+#             */
/*   Updated: 2025/02/27 15:05:35 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*yan;
	t_stack	*sin;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	yan = *stack;
	sin = yan->next;
	yan->next = sin->next;
	sin->next = yan;
	*stack = sin;
}

void	push_stack(t_stack **stack2, t_stack **stack1)
{
	t_stack	*tmp;

	if (!stack1 || !*stack1)
		return ;
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	tmp->next = *stack2;
	*stack2 = tmp;
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*izwar;
	t_stack	*igra;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	izwar = *stack;
	*stack = izwar->next;
	izwar->next = NULL;
	igra = *stack;
	while (igra->next)
		igra = igra->next;
	igra->next = izwar;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*amgaro;
	t_stack	*amzwaro;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	amzwaro = *stack;
	while (amzwaro->next->next)
		amzwaro = amzwaro->next;
	amgaro = amzwaro->next;
	amzwaro->next = NULL;
	amgaro->next = *stack;
	*stack = amgaro;
}
