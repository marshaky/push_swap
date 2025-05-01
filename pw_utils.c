/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pw_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:30:45 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/02 01:43:58 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_split_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	find_index(int *arr, int value, int arg_count)
{
	int	i;

	i = 0;
	while (i < arg_count)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (0);
}

int	ft_sqrt(int num)
{
	int	i;

	i = 2;
	while (i * i < num)
		i++;
	return (i - 1);
}

int	log_two(int nb)
{
	int	n;

	n = 0;
	while (nb)
	{
		nb /= 2;
		n ++;
	}
	return (n);
}
