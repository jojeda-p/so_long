/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:01:12 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/07/02 18:06:37 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_len(char *str)
{
	int	len;

	if (!str)
		return (ft_putstr_len("(null)"));
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
