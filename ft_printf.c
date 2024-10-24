/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbergos <jbergos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:36:20 by jbergos           #+#    #+#             */
/*   Updated: 2024/10/24 03:10:20 by jbergos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h> 

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	results;
	int	i;

	i = 0;
	results = 0;
	va_start(args, format);
	while (format[i])
	{
		if(format[i] == '%' && format[i + 1] == 'c')
		{
			results +=ft_putchar_printf(va_arg(args, int));
			++i;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			results +=ft_putstr_printf(va_arg(args, char *));
			++i;
		}
		else if (format[i] == '%' && format[i + 1] == 'p')
		{
			results +=ft_putptr_printf(va_arg(args, void *));
			++i;
		}
		else if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i'))
		{
			results += ft_putint_printf(va_arg(args, int));
			++i;
		}
		else if (format[i] == '%' && format[i + 1] == 'u')
		{
			results += ft_putuint_printf(va_arg(args,unsigned int));
			++i;
		}
		else if (format[i] == '%' && format[i + 1] == 'x')
		{
			results +=ft_putx_printf(va_arg(args, int));
			++i;
		}
		else if (format[i] == '%' && format[i + 1] == 'X')
		{
			results += ft_putxupper_printf(va_arg(args, int));
			++i;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			results += ft_putchar_printf('%');
			++i;
		}
		else
		{
			write(1, &format[i], 1);
			results++;
		}
			
		++i;
	}
	va_end(args);
	return (results);
}

int main(void)
{
	printf("TEST %%c\n");
	printf("----------------------------------------------\n");
	printf("test avec : char = %c\n", 'a');
	printf("printf : %d\n",printf("'%c'\n", 'a'));
	printf("ft_printf : %d\n",ft_printf("'%c'\n", 'a'));
	printf("\n");
	printf("test avec : char = -1\n");
	printf("printf : %d\n", printf("'%c'\n", -1));
	printf("ft_printf : %d\n", ft_printf("'%c'\n", -1));
	printf("\n");
	printf("test avec char = NULL\n");
	printf("printf : %d\n", printf("'%c\n", '\0'));
	printf("ft_printf : %d\n", ft_printf("'%c\n", '\0'));
	
	printf("TEST %%s\n");
	printf("-------------------------------------------------\n");
	printf("test avec : char * = 'Hello World!\n");
	printf("printf : %d\n", printf("'%s'\n", "Hello World!"));
	printf("ft_printf : %d\n", ft_printf("'%s'\n", "Hello World!"));
	printf("\n");
	printf("test avec char * ''\n");
	printf("printf : %d\n", printf("'%s'\n", ""));
	printf("ft_printf : %d\n", ft_printf("'%s'\n", ""));
	printf("TEST %%p\n");
	printf("-----------------------------------------------------\n");
	printf("test avec : pointeur non null\n");
	int i = 42;
	printf("printf : %d\n", printf("'%p'\n", &i));
	printf("ft_printf : %d\n", ft_printf("'%p'\n", &i));
	printf("\n");
	printf("test avec pointeur NULL\n");
	printf("printf : %d\n", printf("'%p'\n", NULL));
	printf("ft_printf : %d\n", ft_printf("'%p'\n", NULL));
	printf("\n");
	printf("pointeur sur 0\n");
	int *j = 0;
	printf("printf : %d\n", printf("'%p'\n", j));
	printf("ft_printf : %d\n", ft_printf("'%p'\n", j));
	ft_printf("\n");
	printf("test %%i\n");
	printf("---------------------------------------\n");
	printf("printf : %d\n", printf("test : '%i' : '%i' : '%i' : '%i'\n", -42, -042, -0x42, 'c'));
	printf("ft_printf : %d\n", ft_printf("test : '%i' : '%i' : '%i' : '%i'\n", -42, -042, -0x42, 'c'));
	printf("\n");
	printf("test %%d\n");
	printf("------------------------------------------------\n");
	printf("printf %d\n", printf("test : '%d' : '%d' : '%d' : '%d'\n", -2147483647 - 1, -042, -0x42, 'c'));
	printf("ft_printf : %d\n", ft_printf("test : '%d' : '%d' : '%d' : '%d'\n", -2147483647 - 1, -042, -0x42, 'c'));
	printf("\n");
	printf("test %%u\n");
	printf("--------------------------------------------\n");
	printf("test valeur : -1");
	printf("printf : %d\n", printf("'%u'\n", -1));
	printf("ft_printf : %d\n", ft_printf("'%u'\n", -1));
	printf("\n");
	printf("test valeur max\n");
	printf("printf : %d\n", printf("'%u'\n", 2147483647));
	printf("ft_printf : %d\n", ft_printf("''%u\n", 2147483647));
	printf("\n");
	printf("test valeur lambda\n");
	unsigned ui = 0;
	printf("printf : %d\n", printf("'%u'\n", ui));
	printf("ft_printf : %d\n", ft_printf("'%u'\n", ui));
	printf("\n");
	printf("test %%x\n");
	printf("------------------------------------------\n");
	printf("printf : %d\n", printf("'%x'",-1));
	printf("ft_printf : %d\n", ft_printf("'%x'",-1));
	printf("test %%X\n");
	printf("-----------------------------------------------\n");
	printf("printf : %d\n", printf("'%X'\n", -1));
	printf("ft_printf : %d\n", ft_printf("'%X'\n", -1));
	printf("\n");
	printf("test avec %%\n");
	printf("----------------------------------------------\n");
	printf("printf : %d\n", printf("'%%'\n"));
	printf("ft_printf : %d\n", ft_printf("'%%'\n"));
	return (0);
}