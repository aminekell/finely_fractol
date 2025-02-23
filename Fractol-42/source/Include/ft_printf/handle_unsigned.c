/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:44:25 by akella            #+#    #+#             */
/*   Updated: 2024/12/07 23:15:12 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	int				len;
	unsigned int	temp;
	char			*str;

	len = 1;
	temp = n;
	while (temp > 9)
	{
		temp /= 10;
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	handle_unsigned(va_list args)
{
	unsigned int	num;
	char			*num_str;
	int				len;

	num = va_arg(args, unsigned int);
	num_str = ft_utoa(num);
	if (!num_str)
		return (-1);
	ft_putstr(num_str);
	len = ft_strlen(num_str);
	free(num_str);
	return (len);
}
