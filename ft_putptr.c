/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:03:53 by nbarbosa          #+#    #+#             */
/*   Updated: 2025/11/11 11:25:54 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putchar_bis(char c)
{
	write(1, &c, 1);
}

static int	ft_putnbr_ptr(unsigned long long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_putnbr_ptr((n / 16), base);
	ft_putchar_bis(base[n % 16]);
	len++;
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
	{
		ft_putstr("0x");
		len += 2;
		len += ft_putnbr_ptr((unsigned long long)ptr, "0123456789abcdef");
	}
	return (len);
}
