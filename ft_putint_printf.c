/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 03:00:00 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/24 22:25:32 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint_printf(int n)
{
	int		i;
	long	nb;

	i = 0;
	nb = (long)n;
	if (nb < 0)
	{
		nb = -nb;
		i += ft_putchar_printf('-');
	}
	if (nb > 9)
	{
		i += ft_putint_printf(nb / 10);
	}
	i += ft_putchar_printf((nb % 10) + '0');
	return (i);
}
