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

void print_stack(t_stack *stack, char name)
{
	printf("Stack %c: ", name);
	t_stack *temp = stack;
	while (temp)
	{
		printf("[%d | index: %d] -> ", temp->val, temp->index);
		temp = temp->next;
	}
	printf("NULL\n");
}

static void quicksort(int *arr, int low, int high)
{
	int pivot, i, j, temp, pi;
	if (low < high)
	{
		pivot = arr[high];
		i = low - 1;
		j = low;
		while (j < high)
		{
			if (arr[j] < pivot)
			{
				i++;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		temp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = temp;
		pi = i + 1;
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

void assign_indexes(t_stack *stack)
{
	int size, *arr, i;
	t_stack *cur;
	size = stack_len(stack);
	arr = malloc(size * sizeof(int));
	if (!arr)
		return;
	cur = stack;
	i = 0;
	while (i < size)
	{
		arr[i] = cur->val;
		cur = cur->next;
		i++;
	}
	quicksort(arr, 0, size - 1);
	cur = stack;
	while (cur)
	{
		i = 0;
		while (i < size)
		{
			if (cur->val == arr[i])
			{
				cur->index = i;
				break;
			}
			i++;
		}
		cur = cur->next;
	}
	free(arr);
	printf("\nAssigned Indexes:\n");
	print_stack(stack, 'A');
}

int get_max_bits(t_stack *stack)
{
	int max_num, max_bits;
	max_num = stack_len(stack) - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return max_bits;
}

static void process_bit(t_stack **a, t_stack **b, int bit)
{
	int size = stack_len(*a);
	int pushed = 0;
	int i = 0;

	while (i < size)
	{
		if ((((*a)->index >> bit) & 1) == 0)
		{
			push_stack(b, a, 'b');
			printf("pb\n");
			pushed++;
		}
		else
		{
			rotate_stack(a, 'a');
			printf("ra\n");
		}
		i++;
	}

	// Move elements back from B to A
	while (pushed > 0)
	{
		push_stack(a, b, 'a');
		printf("pa\n");
		pushed--;
	}
}

void radix_sort(t_stack **a, t_stack **b)
{
	int max_bits, bit;

	assign_indexes(*a);
	max_bits = get_max_bits(*a);
	bit = 0;
	while (bit < max_bits)
	{
		printf("\n--- Processing Bit %d ---\n", bit);
		print_stack(*a, 'A');
		print_stack(*b, 'B');
		process_bit(a, b, bit);
		printf("\nAfter Bit %d Processing:\n", bit);
		print_stack(*a, 'A');
		print_stack(*b, 'B');
		bit++;
	}
}
