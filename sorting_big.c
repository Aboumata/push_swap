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

int	find_future_rotate(t_stack *a, int threshold)
{
	int	pos;
	int	len;

	pos = 0;
	len = stack_len(a);
	while (a && a->index > threshold)
	{
		pos++;
		a = a->next;
	}
	return (pos <= len / 2) ? pos : len - pos;
}

int	rotation_direction(t_stack *b, int max_index)
{
	int	pos;
	int	len;

	pos = 0;
	len = stack_len(b);
	while (b && b->index != max_index)
	{
		pos++;
		b = b->next;
	}
	return (pos <= len / 2);
}

int	find_max_index(t_stack *stack)
{
	int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	find_rotations_to_max(t_stack *stack, int max_index)
{
	int	position;
	int	len;

	position = 0;
	len = stack_len(stack);
	while (stack && stack->index != max_index)
	{
		position++;
		stack = stack->next;
	}
	return (position <= len / 2) ? position : len - position;
}

void	swap_values(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	*create_sorted_array(t_stack *stack, int size)
{
	int		*arr;
	t_stack	*tmp;
	int		i;
	int		j;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	tmp = stack;
	i = -1;
	while (++i < size)
	{
		arr[i] = tmp->val;
		tmp = tmp->next;
	}
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (arr[i] > arr[j])
				swap_values(&arr[i], &arr[j]);
	}
	return (arr);
}

static void	assign_indexes(t_stack *stack, int *sorted, int size)
{
	t_stack	*current;
	int		i;

	current = stack;
	while (current)
	{
		i = -1;
		while (++i < size)
		{
			if (current->val == sorted[i])
			{
				current->index = i;
				break ;
			}
		}
		current = current->next;
	}
}

void		sort_big(t_stack **a, t_stack **b)
{
	int	size = stack_len(*a);
	int	*sorted = create_sorted_array(*a, size);
	int	chunk_size = (size <= 100) ? 20 : 45;
	int	i = 0;

	assign_indexes(*a, sorted, size);
	free(sorted);
	while (i < size)
	{
		if ((*a)->index <= i + chunk_size)
		{
			push_stack(b, a, 'a');
			if ((*b)->index < i + (chunk_size / 2) && stack_len(*b) > 1)
				rotate_stack(b, 'b');
			i++;
		}
		else if (find_future_rotate(*a, i + chunk_size) <= stack_len(*a) / 2)
			rotate_stack(a, 'a');
		else
			rev_rotate(a, 'a');
	}
	while (*b)
	{
		int	max_index = find_max_index(*b);
		int	rot_dir = rotation_direction(*b, max_index);

		while ((*b)->index != max_index)
		{
			if (rot_dir)
				rotate_stack(b, 'b');
			else
				rev_rotate(b, 'b');
		}
		push_stack(a, b, 'b');
	}
}
