/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:20:25 by akella            #+#    #+#             */
/*   Updated: 2024/11/15 16:04:54 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*s;
	size_t		len;

	s = src;
	len = ft_strlen(s);
	if (dstsize == 0)
		return (len);
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}
