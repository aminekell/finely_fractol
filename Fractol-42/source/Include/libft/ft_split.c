/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:41:37 by akella            #+#    #+#             */
/*   Updated: 2024/11/17 08:22:50 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_res(char **res, int i)
{
	while (i > 0)
	{
		free(res[--i]);
	}
	free(res);
}

static int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	add_word(char **res, char *start, char *end, int i)
{
	int	word_len;

	word_len = end - start;
	res[i] = ft_calloc((word_len + 1), sizeof(char));
	if (!res[i])
		return (-1);
	ft_strlcpy(res[i], start, word_len + 1);
	return (i + 1);
}

static char	**split_words(char const *s, char c, char **res)
{
	char	*start;
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			if (add_word(res, start, (char *)s, i) == -1)
			{
				free_res(res, i);
				return (NULL);
			}
			i++;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	return (split_words(s, c, res));
}
