/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:29:05 by nbarbosa          #+#    #+#             */
/*   Updated: 2025/11/11 10:12:48 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putchar_bis(char c)
{
	write(1, &c, 1);
	return ;
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n < 10)
	{
		ft_putchar_bis(n + '0');
		len++;
	}
	if (n >= 10)
	{
		len += ft_putnbr_unsigned(n / 10);
		len += ft_putnbr_unsigned(n % 10);
	}
	return (len);
}

/*
int main (void) {

ft_putnbr_fd(2147483647, 1);


	
	return 0;
}*/