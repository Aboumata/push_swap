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

void	print_error_and_exit(char **args, int is_split)
{
	if (is_split && args)
		free_args(args);
	write(2, "Error\n", 6);
	exit(1);
}

static void	sort_decision(t_stack **a, t_stack **b, int size)
{
	if (size <= 5)
		sort_small(a, b, size);
	else
		sort_large(a, b, size);
}

static void	validate(char *arg, t_stack **a, char **args)
{
	int	num;
	int	valid;

	valid = 1;
	num = ps_atoi(arg, &valid);
	if (!valid || !is_number(arg) || !check_duplicate(*a, num))
	{
		free_stack(a);
		free_args(args);
		print_error_and_exit(NULL, 0);
	}
	stack_add_back(a, num);
}

static t_stack	*parse_arguments(int argc, char **argv, int *new_argc)
{
	t_stack	*a;
	char	**args;
	int		i;

	a = NULL;
	args = split_args(argc, argv, new_argc);
	if (!args)
		print_error_and_exit(NULL, 0);
	i = 0;
	while (args[i])
	{
		validate(args[i], &a, args);
		i++;
	}
	free_args(args);
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
	free_stack(&b);
}
