/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxupper_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:59:12 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/24 22:30:48 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_toupper_printf(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -32);
	return (c);
}

static int	ft_puthexa(unsigned int nb, int n)
{
	if (nb >= 16)
		n = (ft_puthexa(nb / 16, n));
	n += ft_putchar_printf(ft_toupper_printf(HEXA[nb % 16]));
	return (n);
}

int	ft_putxupper_printf(int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	nb = (unsigned int)n;
	return (ft_puthexa(nb, count));
}
