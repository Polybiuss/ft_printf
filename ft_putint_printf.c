/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 03:00:00 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/23 03:15:40 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putint_printf(int n)
{
	long nb;

	nb = (long)n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_printf('-');
	}
	if (nb > 9)
	{
		ft_putint_printf(nb / 10);
	}
		ft_putchar_printf((nb % 10) + '0');
}