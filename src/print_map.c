/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:29:55 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/11/20 17:01:07 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_images_2(t_data *data, int i, int j)
{
	if (data->map[j][i] == 'C')
	{
		if (data->floor_img)
			mlx_put_image_to_window(data->mlx, data->win,
				data->floor_img, i * 32, j * 32);
		if (data->collect_img)
			mlx_put_image_to_window(data->mlx, data->win,
				data->collect_img, i * 32, j * 32);
	}
	else if (data->map[j][i] == 'E')
	{
		if (data->floor_img)
			mlx_put_image_to_window(data->mlx, data->win,
				data->floor_img, i * 32, j * 32);
		if (data->exit_img)
			mlx_put_image_to_window(data->mlx, data->win,
				data->exit_img, i * 32, j * 32);
	}
}

void	print_images(t_data *data, int i, int j)
{
	if (data->map[j][i] == '1')
	{
		if (data->wall_img)
			mlx_put_image_to_window(data->mlx, data->win,
				data->wall_img, i * 32, j * 32);
	}
	else if (data->map[j][i] == '0')
	{
		if (data->floor_img)
			mlx_put_image_to_window(data->mlx, data->win,
				data->floor_img, i * 32, j * 32);
	}
	else if (data->map[j][i] == 'P')
	{
		if (data->floor_img)
			mlx_put_image_to_window(data->mlx, data->win,
				data->floor_img, i * 32, j * 32);
		if (data->player_img)
			mlx_put_image_to_window(data->mlx, data->win,
				data->player_img, i * 32, j * 32);
		data->player_x = i;
		data->player_y = j;
	}
	else
		print_images_2(data, i, j);
}

// imprime mapa en la ventana
void	print_map(t_data *data)
{
	int	i;
	int	j;

	load_images(data);
	j = 0;
	if (!data->map)
		return ;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			print_images(data, i, j);
			i++;
		}
		j++;
	}
}
