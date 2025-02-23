/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:29:43 by akella            #+#    #+#             */
/*   Updated: 2024/12/06 18:47:19 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_to_hex(char *buffer, unsigned int num,
		int *len, const char *hex_digits)
{
	if (num >= 16)
		convert_to_hex(buffer, num / 16, len, hex_digits);
	buffer[(*len)++] = hex_digits[num % 16];
}

int	handle_hex(va_list args, int is_upper)
{
	unsigned int	num;
	char			buffer[9];
	const char		*hex_digits;
	int				len;

	if (is_upper)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	num = va_arg(args, unsigned int);
	len = 0;
	if (num == 0)
		buffer[len++] = '0';
	else
		convert_to_hex(buffer, num, &len, hex_digits);
	buffer[len] = '\0';
	write(1, buffer, len);
	return (len);
}
