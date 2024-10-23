/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:33:52 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/23 03:01:24 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include<stdarg.h>
#include<unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_printf(int c);
void	ft_putstr_printf(char *s);
void	ft_putptr_printf(void *ptr);
void	ft_putint_printf(int n);
#endif