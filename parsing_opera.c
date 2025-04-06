/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_opera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:04:08 by aboumata          #+#    #+#             */
/*   Updated: 2025/02/27 15:04:11 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(const char *str)
{
	int	i;

	if (!str || *str == '\0')
		return (0);
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str < '0' || *str > '9')
		return (0);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	return (str[i] == '\0');
}

int	ps_atoi(const char *str, int *valid)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10;
		num += (*str - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
		{
			*valid = 0;
			return (0);
		}
		str++;
	}
	return ((int)(num * sign));
}

int	check_duplicate(t_stack *stack, int val)
{
	while (stack)
	{
		if (stack->val == val)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	count_strings(char **strings)
{
	int	count;

	count = 0;
	while (strings[count])
		count++;
	return (count);
}

char	**split_args(int argc, char **argv, int *new_argc)
{
	char	**args;
	char	**temp;
	int		i;
	int		j;

	args = NULL;
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	while (argc > 2 && ++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			return (free_args(args), NULL);
		j = -1;
		while (temp[++j])
		{
			args = add_string_to_array(args, temp[j]);
			if (!args)
				return (free_args(temp), NULL);
		}
		free_args(temp);
	}
	if (!args || !args[0])
		print_error_and_exit(NULL, 0);
	*new_argc = count_strings(args);
	return (args);
}
