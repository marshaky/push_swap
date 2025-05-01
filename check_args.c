/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:01:28 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/02 02:04:59 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *arg)
{
	char	**str;
	int		i;
	int		j;

	str = ft_split(arg, ' ');
	i = 0;
	while (str[++i])
	{
		j = 0;
		if ((str[i][j] == '+' || str[i][j] == '-') && str[i][j + 1])
			j++;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
			{
				ft_free(str);
				return (-1);
			}
			j++;
		}
	}
	ft_free(str);
	if (i == 0)
		exit(0);
	return (i);
}

int	args_count(char **argv)
{
	int	i;
	int	arg_count;
	int	curr_arg_count;

	i = 1;
	arg_count = 0;
	curr_arg_count = 0;
	while (argv[i])
	{
		curr_arg_count = check_arg(argv[i++]);
		if (curr_arg_count == -1)
		{
			print_error();
			exit(1);
		}
		else
			arg_count += curr_arg_count;
	}
	return (arg_count);
}

int	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] == arr[i])
			{
				free(arr);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_if_sorted(int *arr, int arg_count)
{
	int	i;

	i = 0;
	while (i + 1 < arg_count)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			return (0);
	}
	free(arr);
	return (-1);
}

int	val_args(int arg_count, char **argv)
{
	// int		i;
	// int		j;
	// long	num;
	// char	**split;

	// i = 0;
	// while (argv[++i])
	// {
	// 	split = ft_split(argv[i], ' ');
	// 	if (!split)
	// 		return (-1);
	// 	j = 0;
	// 	while (split[j])
	// 	{
	// 		num = atoi_long(split[j]);
	// 		if (num > 2147483647 || num < -2147483648)
	// 		{
	// 			ft_free(split);
	// 			return (-1);
	// 		}
	// 		j++;
	// 	}
	// 	ft_free(split);
	// }
	// return (0);

	long	num;

	if (arg_count == 1)
	{
		num = atoi_long(argv[1]);
		if (num > 2147483647 || num < -2147483648)
			return (-1);
		return (0);
	}
	return (0);
}
