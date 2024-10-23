/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:36:10 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/23 01:26:41 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define hex "0123456789abcdef"

void	ft_puthexa(unsigned long nb)
{
	if (nb >= 15)
	{
		ft_puthexa(nb / 16);
	}
		ft_putchar_printf(hex[nb % 16]);
}

void	ft_putptr_printf(void *ptr)
{
	unsigned long nb;
	if (!ptr)
		return (ft_putstr_printf("(nil)"));
	
	ft_putstr_printf("0x");
	
	nb = (unsigned long)ptr;
	ft_puthexa(nb);
}


