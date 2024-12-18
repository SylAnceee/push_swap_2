/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:15:45 by abreuil           #+#    #+#             */
/*   Updated: 2024/11/20 14:14:43 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	print_digit(long nb, int base, char *symbols, int is_unsigned);
int	print_str(char *str);
int	print_pointer(void *ptr);
int	print_format(char specifier, va_list ap);
int	ft_printf(const char *format, ...);

#endif