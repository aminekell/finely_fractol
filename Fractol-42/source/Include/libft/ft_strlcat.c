/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 04:21:57 by akella            #+#    #+#             */
/*   Updated: 2024/11/17 20:05:57 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		dlen;
	size_t		slen;
	size_t		n;

	if ((!dst && dstsize == 0))
		return (ft_strlen(src));
	d = dst;
	s = src;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen >= dstsize)
		return (dstsize + slen);
	n = dstsize - dlen - 1;
	d += dlen;
	while (*s && n > 0)
	{
		*d++ = *s++;
		n--;
	}
	*d = '\0';
	return (dlen + slen);
}
