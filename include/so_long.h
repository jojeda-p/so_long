/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojeda-p <jojeda-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:13:16 by jojeda-p          #+#    #+#             */
/*   Updated: 2025/11/24 12:08:43 by jojeda-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../src/get_next_line/get_next_line.h"
# include "mlx.h"
# include "../src/ft_printf/ft_printf.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles;
	int		exits;
	int		players;
	char	**map;
}	t_data;

//map
void	print_map(t_data *data);
char	**load_map(char *file_path, t_data *data);
int		free_map(char **map);
void	load_images(t_data *data);

//moves
void	move_up(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);

int		close_window(t_data *data);

//utils
int		count_lines(char *file_path);
int		ft_strleng(char *str);
void	clean_gnl(int fd);

//errors
int		validation(char	*file_path, t_data *data);
int		validation_ber(char *s);
int		validation_content(char	*file_path);
int		line_not_void(char	*file_path);
int		is_rectangular(char *file_path);
int		closed_by_walls(char *file_path);
int		correct_path(char *file_path, t_data *data);

#endif