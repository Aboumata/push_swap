/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:05:10 by aboumata          #+#    #+#             */
/*   Updated: 2025/03/30 17:05:13 by aboumata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	find_max_value(t_stack *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->val > max)
			max = stack->val;
		stack = stack->next;
	}
	return (max);
}

int	partition(int arr[], int izdar_low, int afla_high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[afla_high];
	i = izdar_low - 1;
	j = izdar_low;
	while (j <= afla_high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_int(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_int(&arr[i + 1], &arr[afla_high]);
	return (i + 1);
}

void	quicksort(int arr[], int izdar_low, int afla_high)
{
	int	pi;

	if (izdar_low < afla_high)
	{
		pi = partition(arr, izdar_low, afla_high);
		quicksort(arr, izdar_low, pi - 1);
		quicksort(arr, pi + 1, afla_high);
	}
}
