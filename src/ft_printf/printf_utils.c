/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:59:03 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/07/02 18:05:56 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_u_num_len(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_u_num_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	else
	{
		while (len > 0)
		{
			str[--len] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (str);
}

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len +1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (char)((n % 10) * sign + '0');
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
