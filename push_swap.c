/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:04:29 by aboumata          #+#    #+#             */
/*   Updated: 2025/02/27 15:04:32 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	sort_decision(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_sin(a);
	else if (size == 3)
		sort_krad(a);
	else if (size <= 5)
		sort_koz_smous(a, b);
	else
		radix_sort(a, b);
}

static int	process_args(char **args, t_stack **a, int is_split)
{
	int		i;
	int		num;
	int		valid;

	i = -1;
	while (args[++i])
	{
		valid = 1;
		num = ps_atoi(args[i], &valid);
		if (!valid || !is_number(args[i]) || !check_duplicate(*a, num))
		{
			free_error(a, args, is_split);
			if (is_split)
				free(args);
			print_error_and_exit();
		}
		stack_add_back(a, num);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		new_argc;
	int		is_split;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	args = split_args(argc, argv, &new_argc);
	is_split = (argc == 2);
	if (!args || !process_args(args, &a, is_split))
		print_error_and_exit();
	if (is_split)
	{
		free_args(args);
		free(args);
	}
	if (!is_sorted(a))
		sort_decision(&a, &b, new_argc);
	free_stack(&a);
	return (0);
}
