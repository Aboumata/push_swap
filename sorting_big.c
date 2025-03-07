/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 10:41:58 by aboumata          #+#    #+#             */
/*   Updated: 2025/03/02 10:42:09 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_stack(t_stack *stack, char *name)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", stack->val);
		stack = stack->next;
	}
	printf("\n");
}

#include <stdlib.h>

void	assign_indexes(t_stack *stack)
{
	t_stack	*current;
	int		*array;
	int		size;
	int		i;
	int		j;
	int		temp;

	size = 0;
	current = stack;
	while (current)
	{
		size++;
		current = current->next;
	}
	array = (int *)malloc(size * sizeof(int));
	if (!array)
		return ;
	current = stack;
	i = 0;
	while (current)
	{
		array[i] = current->val;
		i++;
		current = current->next;
	}
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	current = stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->val == array[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}

	free(array);
}

static void process_bit(t_stack **src, t_stack **dst, int bit, char stack_name)
{
	int initial_size = stack_len(*src);
	int processed = 0;

	while (processed < initial_size)
	{
		printf("Processing bit %d: %d\n", bit, (*src)->index);
		if ((((*src)->index >> bit) & 1) == 0)
		{
			printf("Pushing from %c to %c: %d\n", stack_name, stack_name == 'a' ? 'b' : 'a', (*src)->val);
			push_stack(dst, src, stack_name == 'a' ? 'b' : 'a');
		}
		else
		{
			printf("Rotating %c: %d\n", stack_name, (*src)->val);
			rotate_stack(src, stack_name);
		}
		processed++;
	}
	print_stack(*src, stack_name == 'a' ? "Stack A" : "Stack B");
	print_stack(*dst, stack_name == 'a' ? "Stack B" : "Stack A");
}

void radix_sort(t_stack **a, t_stack **b)
{
	int max_bits = 0;
	int bit;
	int size;

	assign_indexes(*a);
	size = stack_len(*a);
	while ((size - 1) >> max_bits)
		max_bits++;
	print_stack(*a, "Stack A");

	bit = 0;
	while (bit < max_bits)
	{
		printf("Processing bit level: %d\n", bit);
		process_bit(a, b, bit, 'a');
		while (*b)
			push_stack(a, b, 'a');
		bit++;
	}
	print_stack(*a, "Final Stack A");
}
