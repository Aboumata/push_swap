/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:51:34 by aboumata          #+#    #+#             */
/*   Updated: 2025/03/31 14:51:35 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	stdin_operations(char *line, t_stack **a, t_stack **b)
{
    if (ft_strncmp(line, "sa\n", 3) == 0)
        swap_stack(a);
    else if (ft_strncmp(line, "sb\n", 3) == 0)
        swap_stack(b);
    else if (ft_strncmp(line, "ss\n", 3) == 0)
    {
        swap_stack(a);
        swap_stack(b);
    }
    else if (ft_strncmp(line, "pa\n", 3) == 0)
        push_stack(a, b);
    else if (ft_strncmp(line, "pb\n", 3) == 0)
        push_stack(b, a);
    else if (ft_strncmp(line, "ra\n", 3) == 0)
        rotate_stack(a);
    else if (ft_strncmp(line, "rb\n", 3) == 0)
        rotate_stack(b);
    else if (ft_strncmp(line, "rr\n", 3) == 0)
    {
        rotate_stack(a);
        rotate_stack(b);
    }
    else if (ft_strncmp(line, "rra\n", 4) == 0)
        rev_rotate(a);
    else if (ft_strncmp(line, "rrb\n", 4) == 0)
        rev_rotate(b);
    else if (ft_strncmp(line, "rrr\n", 4) == 0)
    {
        rev_rotate(a);
        rev_rotate(b);
    }
    else
    {
        free(line);
        write(2, "Error\n", 6);
        exit(1);
    }
}
