/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 10:40:03 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/07/02 18:07:57 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_handle_format(va_list args, const char format);
int		ft_handle_char(int c);
int		ft_handle_string(char *str);
int		ft_handle_pointer(unsigned long long ptr);
int		ft_handle_int(int n);
int		ft_handle_unsigned(unsigned int n);
int		ft_handle_hex(unsigned int n, char format);
int		ft_handle_percent(void);
int		ft_put_hex(unsigned long long n, char format);
int		ft_putchar_len(char c);
int		ft_putstr_len(char *str);
char	*ft_uitoa(unsigned int n);
char	*ft_itoa(int n);

#endif
