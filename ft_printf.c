/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:15:46 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/15 20:49:41 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

#include <stdio.h>

void	ft_convert_base(char *base, int nbr)
{
	if (nbr >= 16)
	{
		ft_convert_base(base, nbr / 16);
		ft_putchar(base[nbr % 16]);
	}
	else
		ft_putchar(base[nbr % 16]);
}

int ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;

	va_start(args, s);
	i = 0;
	while (s[i])
    {
        if (s[i] == '%' && s[i + 1])
        {
			i++;
            if (s[i] == 'c')
				ft_putchar(va_arg(args, int));
			else if (s[i] == 's')
				ft_putstr(va_arg(args, char *));
			else if (s[i] == 'p')
				ft_printaddress(va_arg(args, void *));
			else if (s[i] == 'd')
				ft_putnbr(va_arg(args, int));
			else if (s[i] == 'i')
				ft_putnbr(va_arg(args, int));
			else if (s[i] == 'u')
				ft_putnbr(va_arg(args, int));
			else if (s[i] == 'x')
                ft_convert_base("0123456789abcdef", va_arg(args, int));
			else if (s[i] == 'X')
                ft_convert_base("0123456789ABCDEF", va_arg(args, int));
			else if (s[i] == '%')
				ft_putchar('%');
        }
		else
			ft_putchar(s[i]);
		i++;
    }
	va_end(args);
	return (0);
}

#include <stdio.h>
int main()
{
	char *a = "denufhue";

	printf("%p\n", &a);
	ft_printf("%p\n", &a);
}
