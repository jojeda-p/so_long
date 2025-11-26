/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:43:28 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/06/12 10:54:37 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_hex(unsigned int n, char format)
{
	if (n == 0)
		return (ft_putchar_len('0'));
	return (ft_put_hex(n, format));
}

int	ft_put_hex(unsigned long long n, char format)
{
	char	*base;
	int		len;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		len += ft_put_hex(n / 16, format);
	if (write(1, &base[n % 16], 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_handle_percent(void)
{
	return (ft_putchar_len('%'));
}
