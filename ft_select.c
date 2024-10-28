/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:17:04 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/24 22:32:37 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_select(const char format, va_list args)
{
	int	results;

	results = 0;
	if (format == 'c')
		results += ft_putchar_printf(va_arg(args, int));
	if (format == 's')
		results += ft_putstr_printf(va_arg(args, char *));
	if (format == 'p')
		results += ft_putptr_printf(va_arg(args, void *));
	if (format == 'd' || format == 'i')
		results += ft_putint_printf(va_arg(args, int));
	if (format == 'u')
		results += ft_putuint_printf(va_arg(args, unsigned));
	if (format == 'x')
		results += ft_putx_printf(va_arg(args, int));
	if (format == 'X')
		results += ft_putxupper_printf(va_arg(args, int));
	if (format == '%')
		results += ft_putchar_printf('%');
	return (results);
}
