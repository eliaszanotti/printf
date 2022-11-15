/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:27:00 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/15 20:44:26 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void	ft_printaddress(void *address)
{
	unsigned long	address_long;
	int				i;
	char			str[17];
	char			*base;

	address_long = (long int)address;
	i = 0;
	base = "0123456789abcdef";
	while (address_long)
	{
		str[i] = base[address_long % 16];
		address_long /= 16;
		i++;
	}
	ft_putstr("0x");
	while (i >= 0)
		ft_putchar(str[i--]);
}
