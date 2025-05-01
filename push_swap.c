/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:14:32 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/02 02:05:47 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_sort(t_list **a, t_list **b, int arg_count)
{
	if (arg_count == 2)
		sort_for_two(a);
	else if (arg_count <= 3)
		sort_for_three(a, arg_count);
	else if (arg_count > 3 && arg_count <= 12)
		sort_for_twelve(a, b, arg_count);
	else
	{
		scan_stack_a(a, b, arg_count);
		find_max_b(a, b, arg_count);
	}
}

static void	exec_main(t_list *a, t_list *b, int arg_count, int *arr)
{
	quick_sort(arr, 0, arg_count - 1);
	a = fill_list(a, arr, arg_count);
	free(arr);
	go_sort(&a, &b, arg_count);
	free_list(&a);
	free_list(&b);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		arg_count;
	int		*arr;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	arg_count = args_count(argv);
	if (val_args(arg_count, argv) == -1)
		return (print_error());
	arr = make_array(argv, arg_count);
	if (check_if_sorted(arr, arg_count) == -1)
		return (0);
	if (check_duplicates(arr, arg_count) == 0)
		return (print_error());
	i = 0;
	while (i < arg_count)
		ft_lstadd_back(&a, create_list(arr[i++]));
	exec_main(a, b, arg_count, arr);
}
