/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:21:37 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/05 03:10:50 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

int		args_count(char **argv);
int		check_duplicates(int *arr, int size);
int		check_arg(char *arg);
int		get_split_len(char **str);
int		check_if_sorted(int *arr, int arg_count);
int		val_args(int arg_count, char **argv);
int		print_error(void);
int		find_index(int *arr, int value, int arg_count);
t_list	*create_list(int value);
t_list	*fill_list(t_list *list, int *arr, int arg_count);
void	free_list(t_list **head);
long	atoi_long(const char *str);
int		*make_array(char **arg, int size);
int		log_two(int nb);
int		ft_sqrt(int num);
void	quick_recursion(int *arr, int low, int high, int i);
void	quick_sort(int	*arr, int low, int high);
void	scan_stack_a(t_list **a, t_list **b, int a_size);
void	make_it_first_a(t_list **a, t_list *curr, int *arg_count, int *counter);
void	make_it_first_b(t_list **b, t_list *curr, int *arg_count, int *counter);
void	find_max_b(t_list **a, t_list **b, int arg_count);
void	sort_for_two(t_list **head);
void	sort_for_three(t_list **head, int arg_count);
void	sort_for_twelve(t_list **a, t_list **b, int arg_count);
int		rotate(t_list **head, char c);
int		rotate_stacks(t_list **a, t_list **b);
int		reverse_rotate(t_list **head, char c);
int		reverse_rotate_stacks(t_list **a, t_list **b);
int		swap(t_list **stack, char c);
int		swap_stacks(t_list **stack_a, t_list **stack_b);
int		push(t_list **source, t_list **dest, char c);
void	go_sort(t_list **a, t_list **b, int arg_count);

#endif
