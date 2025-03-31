/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:09:41 by aboumata          #+#    #+#             */
/*   Updated: 2025/03/30 17:09:45 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	push_stack(t_stack **dest, t_stack **src)
{
    t_stack		*tmp;

    if (!src || !*src)
        return ;
    tmp = *src;
    *src = (*src)->next;
    tmp->next = *dest;
    *dest = tmp;
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
