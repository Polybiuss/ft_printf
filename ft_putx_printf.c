/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:10:27 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/24 02:42:18 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>
static int	ft_putxhexa(unsigned nb, int n)
{
	if (nb >= 16)
		n = (ft_putxhexa(nb / 16, n));
	n += ft_putchar_printf(hex[nb % 16]);
	return (n);
}

int	ft_putx_printf(int n)
{
	int count;
	unsigned nb;

	count = 0;
	nb = (unsigned)n;
	printf("En hexa %u\n", n);
	return (ft_putxhexa(nb, count));
}