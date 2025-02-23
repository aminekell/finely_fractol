/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:24:36 by akella            #+#    #+#             */
/*   Updated: 2024/12/06 23:30:29 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex(unsigned long addr, char *buffer)
{
	const char	*hex = "0123456789abcdef";
	int			i;

	i = 19;
	buffer[i--] = '\0';
	while (addr != 0)
	{
		buffer[i--] = hex[addr % 16];
		addr /= 16;
	}
	buffer[i--] = 'x';
	buffer[i--] = '0';
	return (i);
}

int	pointer(va_list args)
{
	void			*ptr;
	char			buffer[20];
	int				start;
	int				len;

	ptr = va_arg(args, void *);
	if (!ptr)
		return ((write(1, "0x0", 3)));
	start = hex((unsigned long)ptr, buffer);
	len = 19 - start - 1;
	write(1, &buffer[start + 1], len);
	return (len);
}
