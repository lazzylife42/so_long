/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:25:20 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/02 16:12:14 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

# define TRUE 1
# define FALSE 0

typedef struct s_error
{
	int		empty;
	int		square;
	int		walls;
	int		overflow;
	int		bad_char;
	int		bad_map;
	int		v_path;
}	t_error;

typedef struct s_data
{
	void	*img;
	char	*addr[6];
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	int		*textures[6];
	char	**map;
	int		map_width;
	int		map_height;
	int		win;
	int		finish;
	int		moves;
}	t_data;

/*	MAP	MAKER		*/

void	map_renderer_init(t_data *data, char **argv);
void	map_renderer(t_data *data);
void	map_sprit_init(t_data *data);
void	map_init(int fd, t_data *data);
void	map_dim(int fd, t_data *data);
void	map_to_tab(int fd, t_data *data);
void	char_to_sprite(t_data *data, char *str);

/*	PLAYER MOVE		*/

int		player_move(int keysym, t_data *data);
void	move_up(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);

/*	GAME STATE	*/

void	game_state(t_data *data);
void	check_c(t_data *data);
void	check_e(t_data *data);
void	check_b(t_data *data);
void	find_player(t_data *data, int *x, int *y);
void	fill_zero(t_data *data);
void	move_booba(t_data *data);

/*	EXIT 		*/

int		on_destroy(t_data *data);
int		off_destroy(t_data *data);
void	free_map(t_data *data);
void	free_sprite(t_data *data);

/*	FLOOD FILL	*/

t_data	*copy_data(const t_data *source);
void	free_data(t_data *copy);
void	p_data(t_data *data);
void	flood_p(t_data *data, int x, int y, char new_char);
void	flood_c(t_data *data, int x, int y, char new_char);
void	flood_z(t_data *data, int x, int y, char new_char);

/*	ERRORS		*/

void	error_init(t_error *error);
void	error_char(t_error *error, char c);
void	error_size(t_error *error, t_data *data);
void	error_check(t_error *error, t_data *data);
void	error_elements(t_error *error, t_data *data);
void	error_square(t_error *error, t_data *data);
void	error_path(t_error *error, t_data *data);
void	error_empty(t_error *error, t_data *data);
void	error_exit(t_error *error, t_data *data, t_data *cp);

#endif