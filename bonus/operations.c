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

void	free_all(char *line, t_stack **a, t_stack **b)
{
	free(line);
	free_stack(a);
	free_stack(b);
}

void	stdin_operations(char *line, t_stack **a, t_stack **b)
{
	if (!line || line[0] == '\n' || line[0] == '\0')
		return (free(line));
	if (!ft_strncmp(line, "sa\n", 3))
		swap_stack(a);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap_stack(b);
	else if (!ft_strncmp(line, "pa\n", 3))
		push_stack(a, b);
	else if (!ft_strncmp(line, "pb\n", 3))
		push_stack(b, a);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate_stack(a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate_stack(b);
	else if (!ft_strncmp(line, "rra\n", 4))
		rev_rotate(a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rev_rotate(b);
	else
	{
		free_all(line, a, b);
		print_error_and_exit(NULL, 0);
	}
	free(line);
}
