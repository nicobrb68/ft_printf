/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:07:47 by nbarbosa          #+#    #+#             */
/*   Updated: 2025/11/11 12:40:16 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_write_to_percent(const char **str)
{
	int	len;

	len = 0;
	while (**str && **str != '%')
	{
		len += ft_putchar((unsigned int)**str);
		(*str)++;
	}
	return (len);
}

static int	ft_types(va_list args, char c)
{
	int		len;

	len = 0;
	if (c == 'i' || c == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		len += ft_putchar(va_arg(args, unsigned int));
	else if (c == '%')
		len += ft_putchar('%');
	else if (c == 'x')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		len += ft_write_to_percent(&str);
		if (*str == '%')
		{
			str++;
			len += ft_types(args, *str);
			str++;
		}
	}
	va_end(args);
	return (len);
}
