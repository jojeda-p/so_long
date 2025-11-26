/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:11:55 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/06/12 10:42:48 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_char(int c)
{
	return (ft_putchar_len(c));
}

int	ft_handle_string(char *str)
{
	if (!str)
		return (ft_putstr_len("(null)"));
	return (ft_putstr_len(str));
}

int	ft_handle_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (ft_putstr_len("(nil)"));
	len += ft_putstr_len("0x");
	len += ft_put_hex(ptr, 'x');
	return (len);
}

int	ft_handle_int(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	if (!num)
		return (-1);
	len = ft_putstr_len(num);
	free(num);
	return (len);
}

int	ft_handle_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	num = ft_uitoa(n);
	if (!num)
		return (-1);
	len = ft_putstr_len(num);
	free(num);
	return (len);
}
