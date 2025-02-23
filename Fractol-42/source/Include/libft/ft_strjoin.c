/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:45:06 by akella            #+#    #+#             */
/*   Updated: 2024/11/15 11:21:11 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		l1;
	int		l2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s3 = ft_calloc(l1 + l2 + 1, sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, l1 + 1);
	ft_strlcat(s3, s2, l1 + l2 + 1);
	return (s3);
}
