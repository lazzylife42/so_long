/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:58:47 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/02 15:59:01 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_p(t_data *data, int x, int y, char new_char)
{
	char	current_char;

	current_char = data->map[y][x];
	if (current_char == 'P')
	{
		data->map[y][x] = new_char;
		if (x + 1 < data->map_width)
			flood_p(data, x + 1, y, new_char);
		if (x - 1 >= 0)
			flood_p(data, x - 1, y, new_char);
		if (y + 1 < data->map_height)
			flood_p(data, x, y + 1, new_char);
		if (y - 1 >= 0)
			flood_p(data, x, y - 1, new_char);
	}
}

void	flood_c(t_data *data, int x, int y, char new_char)
{
	char	current_char;

	current_char = data->map[y][x];
	if (current_char == 'C')
	{
		data->map[y][x] = new_char;
		if (x + 1 < data->map_width)
			flood_c(data, x + 1, y, new_char);
		if (x - 1 >= 0)
			flood_c(data, x - 1, y, new_char);
		if (y + 1 < data->map_height)
			flood_c(data, x, y + 1, new_char);
		if (y - 1 >= 0)
			flood_c(data, x, y - 1, new_char);
	}
}

void	flood_z(t_data *data, int x, int y, char new_char)
{
	char	current_char;

	current_char = data->map[y][x];
	if (current_char == '0')
	{
		data->map[y][x] = new_char;
		if (x + 1 < data->map_width)
			flood_z(data, x + 1, y, new_char);
		if (x - 1 >= 0)
			flood_z(data, x - 1, y, new_char);
		if (y + 1 < data->map_height)
			flood_z(data, x, y + 1, new_char);
		if (y - 1 >= 0)
			flood_z(data, x, y - 1, new_char);
	}
}

static	void	flag_path(t_error *error, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] != '1' && data->map[y][x]
				!= 'E' && data->map[y][x] != 'B')
				error->v_path = TRUE;
			x++;
		}
		y++;
	}
}

void	error_path(t_error *error, t_data *data)
{
	int	i;
	int	x;
	int	y;

	if (error->empty || error->square || error->walls
		|| error->bad_char || error->bad_char)
		return ;
	fill_zero(data);
	find_player(data, &x, &y);
	i = 0;
	flood_p(data, x, y, '0');
	while (i++ < data->map_height * data->map_width)
	{
		flood_c(data, x, y, '0');
		flood_z(data, x, y, 'C');
	}
	flood_c(data, x, y, 'E');
	flag_path(error, data);
}
