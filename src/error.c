/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:09:19 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/11/24 12:09:49 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	element_limits(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			data->players++;
		else if (line[i] == 'C')
			data->collectibles++;
		else if (line[i] == 'E')
			data->exits++;
		i++;
	}
}

int	char_validation(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'E'
			&& line[i] != 'P' && line[i] != 'C' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	correct_elements(char *file_path, t_data *data)
{
	int		fd;
	char	*line;

	data->players = 0;
	data->collectibles = 0;
	data->exits = 0;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (char_validation(line) == 1)
			return (free(line), clean_gnl(fd), 1);
		element_limits(line, data);
		free(line);
		line = get_next_line(fd);
	}
	if (data->players != 1 || data->exits != 1 || data->collectibles < 1)
		return (free(line), clean_gnl(fd), 1);
	return (free(line), clean_gnl(fd), 0);
}

// parseo general
int	validation(char	*file_path, t_data *data)
{
	int	fd;

	if (validation_ber(file_path) == 1)
		return (write(2, "Error\nFormato de mapa incorrecto.", 33), 1);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nNo se pudo abrir el archivo.", 34), 1);
	close(fd);
	if (validation_content(file_path) == 1)
		return (write(2, "Error\nMapa vacio.", 17), 1);
	if (line_not_void(file_path) == 1)
		return (write(2, "Error\nLinea vacia.", 18), 1);
	if (is_rectangular(file_path) == 1)
		return (write(2, "Error\nMapa no rectangular.", 26), 1);
	if (closed_by_walls(file_path) == 1)
		return (write(2, "Error\nMapa no cerrado por muros.", 34), 1);
	if (correct_elements(file_path, data) == 1)
		return (write(2, "Error\nElementos incorrectos.", 29), 1);
	if (correct_path(file_path, data) == 1)
		return (write(2, "Error\nCamino imposible.", 23), 1);
	return (0);
}
