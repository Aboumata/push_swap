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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		new_argc;
	int		valid;
	int		i;
	int		num;
	t_stack	*tmp;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	valid = 1;
	args = split_args(argc, argv, &new_argc);
	i = -1;
	while (++i < new_argc)
	{
		num = ps_atoi(args[i], &valid);
		if (!valid || !is_number(args[i]) || !check_duplicate(stack_a, num))
		{
			free_error(&stack_a, args, (argc == 2));
			write(2, "Error\n", 6);
			return (1);
		}
		stack_add_back(&stack_a, num);
	}
	printf("Initial Stack A:\n");
	tmp = stack_a;
	while (tmp)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
	if (!is_sorted(stack_a))
	{
		printf("Stack is not sorted, applying sorting algorithm...\n");
		if (new_argc == 2)
		{
			printf("Using sort_sin()\n");
			sort_sin(&stack_a);
		}
		else if (new_argc == 3)
		{
			printf("Using sort_krad()\n");
			sort_krad(&stack_a);
		}
		else if (new_argc <= 5)
		{
			printf("Using sort_koz_smous()\n");
			sort_koz_smous(&stack_a, &stack_b);
		}
		else
		{
			printf("Using radix_algo()\n");
			radix_algo(&stack_a, &stack_b);
		}
	}
	else
	{
		printf("Stack is already sorted.\n");
	}
	printf("Final Stack A:\n");
	tmp = stack_a;
	while (tmp)
	{
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("\n");
	free_stack(&stack_a);
	return (0);
}
