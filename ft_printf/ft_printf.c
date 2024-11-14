/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdursun <mdursun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:59:01 by mdursun           #+#    #+#             */
/*   Updated: 2024/10/24 11:54:58 by mdursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long n, const char *base)
{
	int				counter;
	unsigned long	base_len;

	counter = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= base_len)
		counter += ft_putnbr_base(n / base_len, base);
	counter += ft_putchar(base[n % base_len]);
	return (counter);
}

static int	ft_putstr(const char *s)
{
	int	counter;

	counter = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		write(1, s, 1);
		s++;
		counter++;
	}
	return (counter);
}

static int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		counter += ft_putstr("-2147483648");
		return (counter);
	}
	if (n < 0)
	{
		counter += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		counter += ft_putnbr(n / 10);
	counter += ft_putchar((n % 10) + '0');
	return (counter);
}

static int	format_printer(const char c, va_list args)
{
	int	counter;

	counter = 0;
	if (c == 'p')
	{
		counter += ft_putstr("0x");
		counter += ft_putnbr_base
			((unsigned long)va_arg(args, void *), "0123456789abcdef");
	}
	else if (c == 'd')
		counter += ft_putnbr(va_arg(args, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (c == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		counter += ft_putnbr_base
			(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		counter += ft_putnbr_base
			(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'u')
		counter += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		counter;
	va_list	args;

	va_start(args, format);
	counter = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			counter += format_printer(format[i], args);
			if (format[i] == '%')
				counter += ft_putchar('%');
			else if (format[i] == 'c')
				counter += ft_putchar(va_arg(args, int));
		}
		else
			counter += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (counter);
}
