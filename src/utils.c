/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:45:38 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/11/20 14:12:59 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strleng(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	count_lines(char *file_path)
{
	int		fd;
	int		lines_count;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines_count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		lines_count++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (lines_count);
}

void	clean_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
