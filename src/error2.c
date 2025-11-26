/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:47:10 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/11/20 14:12:59 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <string.h>

int	validation_ber(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i < 4)
		return (1);
	if (s[i - 1] != 'r' || s[i - 2] != 'e' || s[i - 3] != 'b'
		|| s[i - 4] != '.')
		return (1);
	return (0);
}

int	validation_content(char	*file_path)
{
	ssize_t	n;
	char	c;
	int		fd;

	fd = open(file_path, O_RDONLY);
	n = read(fd, &c, 1);
	if (n == 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	line_not_void(char	*file_path)
{
	char	*line;
	int		fd;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			return (clean_gnl(fd), 1);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

int	is_rectangular(char *file_path)
{
	char	*line;
	int		fd;
	int		len;
	int		curr_len;

	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 1);
	len = ft_strleng(line);
	if (len <= 0)
		return (free(line), clean_gnl(fd), 1);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		curr_len = ft_strleng(line);
		if (curr_len != len)
			return (free(line), clean_gnl(fd), 1);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
