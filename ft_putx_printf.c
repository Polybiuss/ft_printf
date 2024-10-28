/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 02:10:27 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/24 22:28:10 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putxhexa(unsigned int nb, int n)
{
	if (nb >= 16)
		n = (ft_putxhexa(nb / 16, n));
	n += ft_putchar_printf(HEXA[nb % 16]);
	return (n);
}

int	ft_putx_printf(int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	nb = (unsigned int)n;
	return (ft_putxhexa(nb, count));
}
