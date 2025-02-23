/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:09:17 by akella            #+#    #+#             */
/*   Updated: 2024/12/09 00:02:20 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	disy(char c, va_list args)
{
	if (c == 'x' || c == 'X')
		return (handle_hex(args, c == 'X'));
	if (c == 'c')
		return (handle_char(args));
	if (c == 's')
		return (handle_string(args));
	if (c == 'd' || c == 'i')
		return (handle_integer(args));
	if (c == 'u')
		return (handle_unsigned(args));
	if (c == 'p')
		return (pointer(args));
	if (c == '%')
		return (handle_percent());
	else
		ft_putchar(c);
	return (1);
}
