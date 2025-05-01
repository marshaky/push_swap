/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:19:36 by marshaky          #+#    #+#             */
/*   Updated: 2025/04/27 17:19:38 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	quick_recursion(int *arr, int low, int high, int i)
{
	if (low < high)
	{
		if (i > 0)
		{
			quick_sort(arr, low, i);
			quick_sort(arr, i + 1, high);
		}
		else
			quick_sort(arr, i + 1, high);
	}
}

void	quick_sort(int	*arr, int low, int high)
{
	int	pivot;
	int	j;
	int	i;

	pivot = arr[high];
	j = low;
	i = low - 1;
	while (j < high)
	{
		if (arr[j] <= pivot)
			swap_int(&arr[++i], &arr[j]);
		j++;
	}
	swap_int(&arr[i + 1], &arr[high]);
	quick_recursion(arr, low, high, i);
}
