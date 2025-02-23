/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akella <akella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:25:12 by akella            #+#    #+#             */
/*   Updated: 2024/12/09 00:06:44 by akella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		handle_char(va_list args);
int		handle_string(va_list args);
int		handle_integer(va_list args);
int		handle_unsigned(va_list args);
int		handle_hex(va_list args, int is_upper);
int		pointer(va_list args);
int		handle_percent(void);
int		disy(char specifier, va_list args);

void	ft_putchar(char c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n);

#endif
