/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:57:33 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/01 19:45:49 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_init(t_error *error)
{
	error->empty = FALSE;
	error->square = FALSE;
	error->walls = FALSE;
	error->overflow = FALSE;
	error->bad_char = FALSE;
	error->bad_map = FALSE;
	error->v_path = FALSE;
}

void	error_size(t_error *error, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			error_char(error, data->map[y][x]);
			if (y == 0 || y == data->map_height)
			{
				if (data->map[y][x] != '1')
					error->walls = TRUE;
			}
			else if (y > 0 && y < data->map_height)
			{
				if (data->map[y][0] != '1' ||
					data->map[y][data->map_width - 1] != '1')
					error->walls = TRUE;
			}
			x++;
		}
		y++;
	}
}

void	error_char(t_error *error, char c)
{
	char	*allow;
	int		flag;
	int		i;

	allow = "01PCEB";
	flag = 0;
	i = 0;
	while (*allow)
	{
		if (c == allow[i])
			flag = 1;
		allow++;
	}
	if (flag == 0)
		error->bad_char = TRUE;
}

void	error_empty(t_error *error, t_data *data)
{
	if (data->map_width == 0 || data->map_height == 0
		|| data->map_width == 1 || data->map_height == 1)
		error->empty = TRUE;
	if (data->map_width > 41 || data->map_height > 22)
		error->overflow = TRUE;
}

void	error_square(t_error *error, t_data *data)
{
	int	y;
	int	expected_width;

	y = 0;
	expected_width = data->map_width;
	if (expected_width <= 0)
	{
		error->square = TRUE;
		return ;
	}
	while (y < data->map_height)
	{
		if (data->map[y] == 0
			|| (int)ft_strlen(data->map[y]) != expected_width)
		{
			error->square = TRUE;
			return ;
		}
		y++;
	}
}
