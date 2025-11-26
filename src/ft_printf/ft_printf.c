/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:27:48 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/06/10 12:24:29 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*#include <stdio.h>*/

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] != '\0'))
		{
			i++;
			if (format[i])
				len += ft_handle_format(args, format[i]);
		}
		else
			len += ft_putchar_len(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_handle_format(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_handle_char(va_arg(args, int));
	else if (format == 's')
		len += ft_handle_string(va_arg(args, char *));
	else if (format == 'p')
		len += ft_handle_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_handle_int(va_arg(args, int));
	else if (format == 'u')
		len += ft_handle_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_handle_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_handle_percent();
	else
	{
		len += ft_putchar_len('%');
		len += ft_putchar_len(format);
	}
	return (len);
}
/*int	main(void)
{
	int len_ft, len_std;
	char *str = NULL;
	void *ptr = (void *)0x1234;
	unsigned int uint_max = 4294967295U;

    printf("\n=== Test Char ===\n");
    len_ft = ft_printf("Char: %c\n", 'A');
    printf("ft_printf Len: %d\n", len_ft);
    len_std = printf("Char: %c\n", 'A');
    printf("printf Len: %d\n", len_std);

    printf("\n=== Test String ===\n");
    len_ft = ft_printf("String: %s\n", str);
    printf("ft_printf Len: %d\n", len_ft);
    len_std = printf("String: %s\n", str);
    printf("printf Len: %d\n", len_std);

    printf("\n=== Test Pointer ===\n");
    len_ft = ft_printf("Pointer: %p\n", ptr);
    printf("ft_printf Len: %d\n", len_ft);
    len_std = printf("Pointer: %p\n", ptr);
    printf("printf Len: %d\n", len_std);

    printf("\n=== Test Null Pointer ===\n");
    len_ft = ft_printf("Null pointer: %p\n", (void *)0);
    printf("ft_printf Len: %d\n", len_ft);
    len_std = printf("Null pointer: %p\n", (void *)0);
    printf("printf Len: %d\n", len_std);

    printf("\n=== Test Int Negative ===\n");
    len_ft = ft_printf("Int: %d\n", -2147483648);
    printf("ft_printf Len: %d\n", len_ft);
    len_std = printf("Int: %d\n", -2147483647);
    printf("printf Len: %d\n", len_std);

    printf("\n=== Test Int Positive ===\n");
    len_ft = ft_printf("Int: %i\n", 2147483647);
    printf("ft_printf Len: %d\n", len_ft);
    len_std = printf("Int: %i\n", 2147483647);
    printf("printf Len: %d\n", len_std);

    printf("\n=== Test Unsigned ===\n");
    len_ft = ft_printf("Unsigned: %u\n", uint_max);
    printf("ft_printf Len: %d\n", len_ft);
    len_std = printf("Unsigned: %u\n", uint_max);
    printf("printf Len: %d\n", len_std);

    printf("\n=== Test Hex Lowercase ===\n");
    len_ft = ft_printf("Hex: %x\n", 255);
    printf("ft_printf Len: %d\n", len_ft);
    len_std = printf("Hex: %x\n", 255);
    printf("printf Len: %d\n", len_std);

    printf("\n=== Test Hex Uppercase ===\n");
    len_ft = ft_printf("HEX: %X\n", 255);
    printf("ft_printf Len: %d\n", len_ft);
    len_std = printf("HEX: %X\n", 255);
    printf("printf Len: %d\n", len_std);

    printf("\n=== Test Percent ===\n");
    len_ft = ft_printf("Percent: %%\n");
    printf("ft_printf Len: %d\n", len_ft);
    len_std = printf("Percent: %%\n");
    printf("printf Len: %d\n", len_std);

    return (0);
}*/
