/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:36:20 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/23 03:19:47 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h> 

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	i = 0;

	va_start(args, format);
	while (format[i])
	{
		if(format[i] == '%' && format[i + 1] == 'c')
		{
			ft_putchar_printf(va_arg(args, int));
			++i;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			ft_putstr_printf(va_arg(args, char *));
			++i;
		}
		else if (format[i] == '%' && format[i + 1] == 'p')
		{
			ft_putptr_printf(va_arg(args, void *));
			++i;
		}
		else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			ft_putint_printf(va_arg(args, int));
			++i;
		}
		else if (format[i] == '%' && format[i + 1] == 'u')
		{
			ft_putuint_printf(va_arg(args,unsigned int));
			++i;
		}
		// else if (format[i] == '%' && format[i + 1] == 'x')

		// else if (format[i] == '%' && format[i + 1] == 'X')

		// else if (format[i] == '%' && format[i + 1] == '%')
		
		else
			write(1, &format[i], 1);
		++i;
	}
	va_end(args);
	return (0);
}

int main(void)
{
	printf("TEST %%c\n");
	printf("----------------------------------------------\n");
	printf("test avec : char = %c\n", 'a');
	printf("printf : '%c'\n", 'a');
	ft_printf("ft_printf : '%c'\n", 'a');
	printf("\n");
	printf("test avec : char = -1\n");
	printf("printf : '%c'\n", -1);
	ft_printf("ft_printf : '%c'\n", -1);
	printf("\n");
	printf("test avec char = NULL\n");
	printf("printf : '%c\n", '\0');
	ft_printf("ft_printf : '%c\n", '\0');
	printf("TEST %%s\n");
	printf("-------------------------------------------------\n");
	printf("test avec : char * = 'Hello World!\n");
	printf("printf : '%s'\n", "Hello World!");
	ft_printf("ft_printf : '%s'\n", "Hello World!");
	printf("\n");
	printf("test avec char * ''\n");
	printf("printf : '%s'\n", "");
	ft_printf("ft_printf : '%s'\n", "");
	printf("TEST %%p\n");
	printf("-----------------------------------------------------\n");
	printf("test avec : pointeur non null\n");
	int i = 42;
	printf("printf : '%p'\n", &i);
	ft_printf("ft_printf : '%p'\n", &i);
	printf("\n");
	printf("test avec pointeur NULL\n");
	printf("printf : '%p'\n", NULL);
	ft_printf("ft_printf : '%p'\n", NULL);
	printf("\n");
	printf("pointeur sur 0\n");
	int *j = 0;
	printf("printf : '%p'\n", j);
	ft_printf("ft_printf : '%p'\n", j);
	ft_printf("\n");
	printf("test %%i\n");
	printf("---------------------------------------\n");
	printf("test : '%i' : '%i' : '%i' : '%i'\n", -42, -042, -0x42, 'c');
	ft_printf("test : '%i' : '%i' : '%i' : '%i'\n", -42, -042, -0x42, 'c');
	printf("\n");
	printf("test %%d\n");
	printf("------------------------------------------------\n");
	printf("test : '%d' : '%d' : '%d' : '%d'\n", -2147483647 -1, -042, -0x42, 'c');
	ft_printf("test : '%d' : '%d' : '%d' : '%d'\n", -2147483647 -1, -042, -0x42, 'c');
	return (0);
}