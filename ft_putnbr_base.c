/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:29:05 by nbarbosa          #+#    #+#             */
/*   Updated: 2025/11/11 10:23:19 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putchar_bis(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr_base(unsigned int n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_putnbr_base((n / 16), base);
	ft_putchar_bis(base[n % 16]);
	len++;
	return (len);
}

/*
int main (void) {

ft_putnbr_fd(2147483647, 1);


	
	return 0;
}*/