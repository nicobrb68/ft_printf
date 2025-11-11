/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf..h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 15:11:13 by nbarbosa          #+#    #+#             */
/*   Updated: 2025/11/11 10:13:44 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(unsigned int c);
int	ft_putstr(const char *s);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_base(unsigned int n, char *base);
int	ft_putnbr(int n);
int	ft_putptr(void *ptr);
#endif 