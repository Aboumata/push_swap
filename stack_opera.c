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

void	push_stack(t_stack **dest, t_stack **src, char name)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	print_opera("p");
	write(1, (name == 'a') ? "b\n" : "a\n", 2);
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
