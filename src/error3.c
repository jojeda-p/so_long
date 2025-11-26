/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:16:52 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/11/20 14:13:00 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_first_and_last(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	validate_first_line(int fd, int *len)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	*len = ft_strleng(line);
	if (*len <= 0 || check_first_and_last(line))
		return (free(line), 1);
	return (free(line), 0);
}

static int	validate_middle_lines(int fd, int len, int rows)
{
	char	*line;
	int		i;
	int		curr_len;

	i = 0;
	while (i < rows)
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		curr_len = ft_strleng(line);
		if (curr_len != len || curr_len < 1)
			return (free(line), 1);
		if (line[0] != '1' || line[len - 1] != '1')
			return (free(line), 1);
		free(line);
		i++;
	}
	return (0);
}

static int	validate_last_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	if (check_first_and_last(line))
		return (free(line), 1);
	return (free(line), 0);
}

int	closed_by_walls(char *file_path)
{
	int	fd;
	int	len;
	int	total_lines;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (1);
	total_lines = count_lines(file_path);
	if (total_lines < 3)
		return (close(fd), 1);
	if (validate_first_line(fd, &len))
		return (clean_gnl(fd), 1);
	if (validate_middle_lines(fd, len, total_lines - 2))
		return (clean_gnl(fd), 1);
	if (validate_last_line(fd))
		return (clean_gnl(fd), 1);
	return (close(fd), 0);
}
