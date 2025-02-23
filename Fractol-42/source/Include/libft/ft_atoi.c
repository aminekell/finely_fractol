/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:37:44 by akella            #+#    #+#             */
/*   Updated: 2024/11/20 14:20:27 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			s;
	long long	r;
	long long	r2;

	s = 1;
	r = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r2 = r;
		r = r * 10 + (*str - '0');
		if ((r / 10 != r2) && s == 1)
			return (-1);
		if ((r / 10 != r2) && s == -1)
			return (0);
		str++;
	}
	return ((int)(r * s));
}
