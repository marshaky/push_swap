/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:15:33 by marshaky          #+#    #+#             */
/*   Updated: 2025/05/02 02:28:20 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(int value)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->value = value;
	new_list->index = -1;
	new_list->next = NULL;
	return (new_list);
}

void	free_list(t_list **head)
{
	t_list	*tmp;

	if (head)
	{
		while (*head)
		{
			tmp = *head;
			*head = (*head)->next;
			free(tmp);
		}
	}
}

t_list	*fill_list(t_list *list, int *arr, int arg_count)
{
	t_list	*head;
	int		i;

	head = list;
	while (list)
	{
		i = find_index(arr, list->value, arg_count);
		list->index = i;
		list = list->next;
	}
	return (head);
}

static void	fill_array(char **splitted, int	*arr, int size)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	j = 0;
	while (j < size)
	{
		num = atoi_long(splitted[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			ft_free(splitted);
			free(arr);
			exit(print_error());
		}
		arr[j++] = ft_atoi(splitted[i++]);
	}
}

int	*make_array(char **arg, int size)
{
	int		i;
	char	*str;
	int		*arr;
	char	**splitted;

	i = 1;
	str = NULL;
	while (arg[i])
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, arg[i++]);
	}
	splitted = ft_split(str, ' ');
	free(str);
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	fill_array(splitted, arr, size);
	ft_free(splitted);
	return (arr);
}
