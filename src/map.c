/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:44:42 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/11/20 15:46:10 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "get_next_line/get_next_line.h"
#include "mlx.h"
// liberar mapa
int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

// helper para load map
static void	from_ber_to_map(t_data *data, int fd)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strleng(line);
		if (line[len] == '\n')
			line[len] = '\0';
		data->map[i++] = line;
		line = get_next_line(fd);
	}
	free(line);
	data->map[i] = NULL;
}

// abrir archivo.ber y generar un char ** del mapa
char	**load_map(char *file_path, t_data *data)
{
	int		fd;
	int		lines_count;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines_count = count_lines(file_path);
	if (lines_count <= 0)
		return (close(fd), NULL);
	data->map = malloc(sizeof(char *) * (lines_count + 1));
	if (!data->map)
		return (close(fd), NULL);
	from_ber_to_map(data, fd);
	return (close(fd), data->map);
}

// cargar imagenes
void	load_images(t_data *data)
{
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"assets/wall.xpm", &data->img_width, &data->img_height);
	data->floor_img = mlx_xpm_file_to_image(data->mlx,
			"assets/floor.xpm", &data->img_width, &data->img_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx,
			"assets/player.xpm", &data->img_width, &data->img_height);
	data->collect_img = mlx_xpm_file_to_image(data->mlx,
			"assets/collectible.xpm", &data->img_width, &data->img_height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx,
			"assets/exit.xpm", &data->img_width, &data->img_height);
	data->moves = 0;
}
