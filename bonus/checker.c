/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:40:01 by aboumata          #+#    #+#             */
/*   Updated: 2025/03/30 17:40:02 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
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
		if (needs_free)
			free_args(args);
		print_error_and_exit();
	}
	stack_add_back(a, num);
}

static t_stack	*parse_arguments(int argc, char **argv, int *new_argc,
		int *needs_free)
{
	t_stack	*a;
	char	**args;
	int		i;

	a = NULL;
	args = split_args(argc, argv, new_argc, needs_free);
	if (!args)
		print_error_and_exit();
	i = 0;
	while (args[i])
	{
		validate(args[i], &a, args);
		i++;
	}
	if (*needs_free)
		free_args(args);
	return (a);
}

static void	execute(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		stdin_operations(line, a, b);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		new_argc;
	int		needs_free;

	if (argc < 2)
		return (0);
	a = parse_arguments(argc, argv, &new_argc, &needs_free);
	b = NULL;
	execute(&a, &b);
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
}
