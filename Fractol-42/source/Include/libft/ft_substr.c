/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 01:21:25 by akella            #+#    #+#             */
/*   Updated: 2024/11/03 21:02:40 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	s1_len;
	size_t	s2_len;

	if (!s)
		return (NULL);
	s1_len = ft_strlen(s);
	if (start >= s1_len)
		return (ft_strdup(""));
	s2_len = s1_len - start;
	if (s2_len > len)
		s2_len = len;
	s2 = malloc((s2_len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s + start, s2_len + 1);
	return (s2);
}
