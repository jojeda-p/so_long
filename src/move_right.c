/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:05:32 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/11/20 16:28:21 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	update_player_tile(t_data *data)
{
	if (data->map[data->player_y][data->player_x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit_img, data->player_x * 32, data->player_y * 32);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor_img, data->player_x * 32, data->player_y * 32);
}

void	move_right(t_data *data)
{
	char	next_pos;

	next_pos = data->map[data->player_y][data->player_x + 1];
	if (next_pos == '1')
		return ;
	if (next_pos == 'E' && data->collectibles > 0)
		return ;
	update_player_tile(data);
	data->player_x++;
	if (next_pos == 'C')
	{
		data->collectibles--;
		data->map[data->player_y][data->player_x] = '0';
	}
	mlx_put_image_to_window(data->mlx, data->win,
		data->player_img, data->player_x * 32, data->player_y * 32);
	data->moves++;
	ft_printf("%d\n", data->moves);
	if (next_pos == 'E')
		close_window(data);
}
