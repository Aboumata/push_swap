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

static void	validate_and_add(char *arg, t_stack **a)
{
	int	num;
	int	valid;

	valid = 1;
	num = ps_atoi(arg, &valid);
	if (!valid || !is_number(arg) || !check_duplicate(*a, num))
	{
		free_stack(a);
		print_error_and_exit();
	}
	stack_add_back(a, num);
}

static t_stack	*parse_arguments(int argc, char **argv, int *new_argc)
{
	t_stack	*a;
	char	**args;
	int		i;
	int		is_split;

	a = NULL;
	args = split_args(argc, argv, new_argc);
	is_split = (argc == 2);
	if (!args)
		print_error_and_exit();
	i = 0;
	while (args[i])
		validate_and_add(args[i++], &a);
	if (is_split)
	{
		free_args(args);
		free(args);
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		new_argc;

	if (argc < 2)
		return (0);
	a = parse_arguments(argc, argv, &new_argc);
	b = NULL;
	if (!is_sorted(a))
		sort_decision(&a, &b, new_argc);
	free_stack(&a);
}