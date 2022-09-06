/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponcele <gponcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:48:25 by gponcele          #+#    #+#             */
/*   Updated: 2022/09/01 15:56:59 by gponcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_formats(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_formats(va_list ap, const char format)
{
	int	a;

	a = 0;
	if (format == 'c')
		a = ft_print_char(va_arg(ap, int));
	else if (format == 's')
		a = ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		a = ft_print_ptr(va_arg(ap, unsigned long));
	else if (format == 'd' || format == 'i')
		a = ft_print_nbr(va_arg(ap, int));
	else if (format == 'u')
		a = ft_print_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		a = ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		a = ft_print_percent();
	return (a);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	ap;
	int		return_value;

	i = -1;
	return_value = 0;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%' && ft_check_formats(s[i + 1], "cspdiuxX%"))
		{
			return_value += ft_formats(ap, s[i + 1]);
			i++;
		}
		else if (s[i] == '%' && !ft_check_formats(s[i + 1], "cspdiuxX%"))
		{
			return_value += ft_print_char(s[i + 1]);
			i++;
		}
		else
			return_value += ft_print_char(s[i]);
	}
	va_end(ap);
	return (return_value);
}

/*#include <stdio.h>
#include <limits.h>
int main(void)
{
	char *str = "Hello";
	int integer = -2147;
	int digit = -2147;
	unsigned int unsigned_decimal = 4294967295;
	unsigned int hex_x = -128;
	int hex_X = -128;
	char c = 'c';
	//int ptr = &integer;

ft_printf("-------------------------------------\n");
ft_printf("|    My ft_printf implementation    |\n");
ft_printf("-------------------------------------\n");
ft_printf("String is: %s\n", str);
ft_printf("Char is: %c\n", c);
ft_printf("Integer is: %i\n", integer);
ft_printf("Digit is: %d\n", digit);
ft_printf("Unsigned is: %u\n", unsigned_decimal);
ft_printf("Hexadecimal x is: %x\n", hex_x);
ft_printf("Hexadecimal X is: %X\n", hex_X);
ft_printf("Pointer is: %p %p\n", LONG_MIN, LONG_MAX);
ft_printf("Percentage sign: %%");

ft_printf("\n");

printf("-------------------------------------\n");
printf("|            Real printf            |\n");
printf("-------------------------------------\n");
printf("String is: %s\n", str);
printf("Char is: %c\n", c);
printf("Integer is: %i\n", integer);
printf("Digit is: %d\n", digit);
printf("Unsigned is: %u\n", unsigned_decimal);
printf("Hexadecimal x is: %x\n", hex_x);
printf("Hexadecimal X is: %X\n", hex_X);
printf("Pointer is: %p %p\n", LONG_MIN, LONG_MAX);
printf("Percentage sign: %%\n");
return 0;
}*/

/*#include <stdio.h>
int main()
{
	char *str = "Hello";
	int integer = -1;
	int digit = -2147483648;
	unsigned int max_u_int = 4294967295;
	unsigned int hex_x = -128;
	int hex_X = -128;
	ft_printf("-------------------------------------\n");
	ft_printf("|    My ft_printf implimentation    |\n");
	ft_printf("-------------------------------------\n");
	int ret_ft_printf = ft_printf("Value : %s\n", str);
	printf("Return Value: %d\n", ret_ft_printf);
	printf("-------------------------------------\n");
	printf("|            Real printf            |\n");
	printf("-------------------------------------\n");
	int ret_printf = printf("Value : %s\n", str);
	printf("Return Value : %d\n", ret_printf);
}*/