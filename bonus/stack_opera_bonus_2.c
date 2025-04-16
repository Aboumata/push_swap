/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opera_bonus_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:14:52 by aboumata          #+#    #+#             */
/*   Updated: 2025/04/15 13:14:53 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_stack **a, t_stack **b)
{
    swap_stack(a);
    swap_stack(b);
}

void	rr(t_stack **a, t_stack **b)
{
    rotate_stack(a);
    rotate_stack(b);
}

void	rrr(t_stack **a, t_stack **b)
{
    rev_rotate(a);
    rev_rotate(b);
}
