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

void	print_opera(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	swap_stack(t_stack **stack, char name)
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
	print_opera("s");
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	push_stack(t_stack **stack2, t_stack **stack1, char name1)
{
	t_stack	*tmp;
	char	name2;

	if (!stack1 || !*stack1)
		return ;
	tmp = *stack1;
	*stack1 = (*stack1)->next;
	tmp->next = *stack2;
	*stack2 = tmp;
	if (name1 == 'a')
		name2 = 'b';
	else
		name2 = 'a';
	print_opera("p");
	write(1, &name2, 1);
	write(1, "\n", 1);
}

void	rotate_stack(t_stack **stack, char name)
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
	print_opera("r");
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	rev_rotate(t_stack **stack, char name)
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
	print_opera("rr");
	write(1, &name, 1);
	write(1, "\n", 1);
}
