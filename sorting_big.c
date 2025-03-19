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

int	find_position(t_stack *stack, int target_index)
{
	int	pos = 0;

	while (stack)
	{
		if (stack->index == target_index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	rotation_direction(t_stack *b, int max_index)
{
	int	pos = 0;
	int	len = stack_len(b);
	t_stack	*current = b;

	while (current && current->index != max_index)
	{
		pos++;
		current = current->next;
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

int	find_next_in_range(t_stack *a, int current_max, int chunk_size)
{
	int	pos = 0;
	int	best_pos = -1;
	int	min_index = (current_max > chunk_size) ?
		current_max - chunk_size + 1 : 0;
	int	len = stack_len(a);

	while (a && pos < len * 2)
	{
		if (a->index >= min_index && a->index <= current_max)
		{
			best_pos = pos % len;
			break;
		}
		pos++;
		a = a->next;
	}
	if (best_pos == -1) return (0);
	return (best_pos <= len / 2) ? best_pos : len - best_pos;
}

static void	optimized_push_chunks(t_stack **a, t_stack **b, int size)
{
	int	chunk_size = (size <= 100) ? 20 : 45;
	int	next_target = chunk_size;
	int	pushed = 0;
	int	rotate_count = 0;

	while (pushed < size)
	{
		if ((*a)->index <= next_target)
		{
			push_stack(b, a, 'a');
			if ((*b)->index < (next_target - (chunk_size / 2)) && stack_len(*b) > 1)
				rotate_stack(b, 'b');
			pushed++;
			next_target = (pushed % chunk_size == 0) ?
				next_target + chunk_size : next_target + 1;
			if (next_target >= size) next_target = size - 1;
			rotate_count = 0;
		}
		else
		{
			if (rotate_count++ > size/2)
			{
				rev_rotate(a, 'a');
				rotate_count = 0;
			}
			else
				rotate_stack(a, 'a');
		}
	}
}

void		sort_big(t_stack **a, t_stack **b)
{
	int	size = stack_len(*a);
	int	*sorted = create_sorted_array(*a, size);
	int	max_index;

	assign_indexes(*a, sorted, size);
	free(sorted);
	optimized_push_chunks(a, b, size);

	while (*b)
	{
		max_index = find_max_index(*b);
		int	rot_dir = rotation_direction(*b, max_index);
		int	rotations = rot_dir ?
			find_position(*b, max_index) :
			stack_len(*b) - find_position(*b, max_index);

		while (rotations-- > 0)
		{
			if (rot_dir)
				rotate_stack(b, 'b');
			else
				rev_rotate(b, 'b');
		}
		push_stack(a, b, 'b');
	}
}
