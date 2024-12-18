/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:26:41 by abreuil           #+#    #+#             */
/*   Updated: 2024/11/20 15:39:52 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <limits.h> 

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
//int main (void)
//{
//    // Basic string
//    printf("Original printf: %s\n", "Hello, world!");
//    ft_printf("Custom ft_printf: %s\n", "Hello, world!");
//
//    // Integer
//    printf("Original printf: %d\n", 42);
//    ft_printf("Custom ft_printf: %d\n", 42);
//
//    // Hexadecimal
//    printf("Original printf: %x\n", 255);
//    ft_printf("Custom ft_printf: %x\n", 255);
//
//    // Unsigned integer
//    printf("Original printf: %u\n", 429496);
//    ft_printf("Custom ft_printf: %u\n", 429496);
//
//    // Pointer
//    printf("Original printf: %p\n", (void *)42);
//    ft_printf("Custom ft_printf: %p\n", (void *)42);
//
//    // Characters
//    printf("Original printf: %c\n", 'A');
//    ft_printf("Custom ft_printf: %c\n", 'A');
//
//    // Percent sign
//    printf("Original printf: %%\n");
//    ft_printf("Custom ft_printf: %%\n");
//}