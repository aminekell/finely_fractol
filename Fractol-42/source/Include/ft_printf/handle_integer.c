/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:39:46 by akella            #+#    #+#             */
/*   Updated: 2024/12/07 23:20:27 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

int	handle_integer(va_list args)
{
	int	num;

	num = va_arg(args, int);
	ft_putnbr(num);
	return (ft_numlen(num));
}
