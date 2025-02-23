/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:35:01 by akella            #+#    #+#             */
/*   Updated: 2024/11/11 04:50:25 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	char	*e;

	if (!s1 || !set)
		return (NULL);
	s = (char *)s1;
	e = (char *)s1 + ft_strlen(s1);
	while (*s && ft_strchr(set, *s))
		s++;
	while (e > s && ft_strchr(set, *(e - 1)))
		e--;
	return (ft_substr(s, 0, e - s));
}
