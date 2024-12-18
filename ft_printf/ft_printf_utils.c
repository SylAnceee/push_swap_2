/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:15:57 by abreuil           #+#    #+#             */
/*   Updated: 2024/11/20 14:15:12 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include "limits.h"

int	print_digit(long nb, int base, char *symbols, int is_unsigned)
{
	int	count;

	count = 0;
	if (is_unsigned == 0 && nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb >= base)
		count += print_digit(nb / base, base, symbols, is_unsigned);
	count += write(1, &symbols[nb % base], 1);
	return (count);
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
		count += write(1, str++, 1);
	return (count);
}

int	print_pointer(void *ptr)
{
	int				count;
	unsigned long	addr;

	count = 0;
	addr = (unsigned long)ptr;
	if (!ptr)
		return (count += write(1, "(nil)", 5));
	else if (ptr == (void *)LONG_MIN)
		return (count += write(1, "0x8000000000000000", 18));
	else if (ptr == (void *)ULONG_MAX)
		return (count += write(1, "0xffffffffffffffff", 18));
	else
	{
		count += write(1, "0x", 2);
		count += print_digit(addr, 16, "0123456789abcdef", 1);
	}
	return (count);
}

int	print_format(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (write(1, &(char){(char)va_arg(ap, int)}, 1));
	else if (specifier == 's')
		return (print_str(va_arg(ap, char *)));
	else if (specifier == 'p')
		return (print_pointer(va_arg(ap, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_digit(va_arg(ap, int), 10, "0123456789", 0));
	else if (specifier == 'u')
		return (print_digit(
				va_arg(ap, unsigned int), 10, "0123456789", 1));
	else if (specifier == 'x')
		return (print_digit(
				va_arg(ap, unsigned int), 16, "0123456789abcdef", 1));
	else if (specifier == 'X')
		return (print_digit(
				va_arg(ap, unsigned int), 16, "0123456789ABCDEF", 1));
	return (write(1, &specifier, 1));
}
