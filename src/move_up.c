/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:50:32 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/11/20 16:27:38 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move_up_action(t_data *data)
{
	if (data->map[data->player_y][data->player_x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit_img, data->player_x * 32, data->player_y * 32);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor_img, data->player_x * 32, data->player_y * 32);
	data->player_y--;
	mlx_put_image_to_window(data->mlx, data->win,
		data->player_img, data->player_x * 32, data->player_y * 32);
}

void	move_up(t_data *data)
{
	char	n;

	n = data->map[data->player_y - 1][data->player_x];
	if (n == '1' || (n == 'E' && data->collectibles > 0))
		return ;
	data->moves++;
	ft_printf("%d\n", data->moves);
	if (n == 'C')
	{
		data->collectibles--;
		data->map[data->player_y - 1][data->player_x] = '0';
		move_up_action(data);
		return ;
	}
	if (n == 'E')
	{
		move_up_action(data);
		close_window(data);
		return ;
	}
	move_up_action(data);
}
