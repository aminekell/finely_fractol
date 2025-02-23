/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:23:09 by akella            #+#    #+#             */
/*   Updated: 2024/12/09 00:18:50 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(const char **format, va_list args)
{
	int	len;

	len = 0;
	(*format)++;
	if (**format == '\0')
		return (-1);
	len = disy(**format, args);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_len;
	int		len;

	total_len = 0;
	va_start(args, format);
	while (*format)
	{
		len = 0;
		if (*format == '%')
		{
			len = handle_format(&format, args);
			if (len == -1)
				break ;
			total_len += len;
		}
		else
		{
			ft_putchar(*format);
			total_len++;
		}
		format++;
	}
	va_end(args);
	return (total_len);
}
