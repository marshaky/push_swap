/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:40:09 by marshaky          #+#    #+#             */
/*   Updated: 2025/04/29 18:58:43 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static char	**fill_string(char **split, char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = -1;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && s++)
				len++;
			split[++i] = ft_substr(s - len, 0, len);
			if (split[i] == NULL)
			{
				ft_free(split);
				return (NULL);
			}
		}
		else
			s++;
	}
	split[++i] = NULL;
	return (split);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			i--;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	split = fill_string(split, s, c);
	return (split);
}
