/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   booba.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:57:36 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/01 13:18:29 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	move_booba_even(t_data *data, int x, int y)
{
	if (x < data->map_width - 1 && data->map[y][x + 1] == '0')
	{
		data->map[y][x + 1] = 'B';
		data->map[y][x] = '0';
	}
}

static	void	move_booba_odd(t_data *data, int x, int y)
{
	if (x > 0 && data->map[y][x - 1] == '0')
	{
		data->map[y][x - 1] = 'B';
		data->map[y][x] = '0';
	}
}

void	move_booba(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'B')
			{
				if (data->moves % 3 == 0)
					move_booba_even(data, x, y);
				else
					move_booba_odd(data, x, y);
			}
			x++;
		}
		y++;
	}
}
