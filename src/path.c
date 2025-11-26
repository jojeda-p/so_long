/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:01:34 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/11/24 12:15:36 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initialize_p(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(char **map, t_data *data, int y, int x)
{
	if (y < 0 || !map[y])
		return ;
	if (x < 0 || !map[y][x])
		return ;
	if (map[y][x] == 'E')
	{
		data->exits--;
		return ;
	}
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'E')
		return ;
	if (map[y][x] == 'C')
		data->collectibles--;
	map[y][x] = 'V';
	flood_fill(map, data, y + 1, x);
	flood_fill(map, data, y - 1, x);
	flood_fill(map, data, y, x + 1);
	flood_fill(map, data, y, x - 1);
}

static void	restore_state(t_data *data, int auxc, int auxe)
{
	data->collectibles = auxc;
	data->exits = auxe;
	data->map = NULL;
}

// checkeo de mapa posible con floodfill
int	correct_path(char *file_path, t_data *data)
{
	char	**map2;
	int		auxc;
	int		auxe;

	auxc = data->collectibles;
	auxe = data->exits;
	map2 = load_map(file_path, data);
	if (!map2)
	{
		restore_state(data, auxc, auxe);
		return (1);
	}
	initialize_p(map2, data);
	flood_fill(map2, data, data->player_y, data->player_x);
	if (data->collectibles > 0 || data->exits == 1)
	{
		free_map(map2);
		restore_state(data, auxc, auxe);
		return (1);
	}
	free_map(map2);
	restore_state(data, auxc, auxe);
	return (0);
}
