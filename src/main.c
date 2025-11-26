/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:02:59 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/11/20 17:31:00 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// destruye todas las imagenes y cierra ventana, liberandolo
int	close_window(t_data *data)
{
	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
	if (data->floor_img)
		mlx_destroy_image(data->mlx, data->floor_img);
	if (data->player_img)
		mlx_destroy_image(data->mlx, data->player_img);
	if (data->collect_img)
		mlx_destroy_image(data->mlx, data->collect_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map)
		free_map(data->map);
	exit(0);
}

// detecta las tclas pulsadas para ejecutar su funcion de movimiento
int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 119)
		move_up(data);
	else if (keycode == 97)
		move_left(data);
	else if (keycode == 115)
		move_down(data);
	else if (keycode == 100)
		move_right(data);
	return (0);
}

// y_max
int	y(char *file_path)
{
	int	y;

	y = count_lines(file_path);
	return (y * 32);
}

// x_max
int	x(char *file_path)
{
	int		fd;
	char	*line;
	int		x;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	x = ft_strleng(line);
	free(line);
	clean_gnl(fd);
	return (x * 32);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (1);
	if (validation(argv[1], &data) == 1)
		return (1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, x(argv[1]), y(argv[1]), "so_long");
	if (!data.win)
		return (1);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);
	if (!load_map(argv[1], &data))
		return (1);
	print_map(&data);
	mlx_loop(data.mlx);
	return (0);
}
