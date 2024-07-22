/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:21:11 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/02 16:00:20 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_state(t_data *data)
{
	check_c(data);
	check_e(data);
	if (data->finish == TRUE && data->win == TRUE)
	{
		ft_printf("YOU WIN :D !\n");
		on_destroy(data);
	}
	else if (data->finish == TRUE && data->win == FALSE)
	{
		ft_printf("YOU LOSE :/ !\n");
		on_destroy(data);
	}
	ft_printf("MOVES : %d\n", data->moves);
}

void	check_c(t_data *data)
{
	int	flag;
	int	x;
	int	y;	

	flag = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'C')
				flag = 1;
			x++;
		}
		y++;
	}
	if (flag == 0)
		data->win = TRUE;
	else
		data->win = FALSE;
}

void	check_e(t_data *data)
{
	int	flag;
	int	x;
	int	y;	

	flag = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'E')
				flag = 1;
			x++;
		}
		y++;
	}
	if (flag == 0)
		data->finish = TRUE;
	else
		data->finish = FALSE;
}

void	find_player(t_data *data, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (*y < data->map_height)
	{
		*x = 0;
		while (*x < data->map_width)
		{
			if (data->map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	fill_zero(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == '0')
			{
				if (data->map[y + 1][x] == '1' && data->map[y][x + 1] == '1'
					&& data->map[y - 1][x] == '1' && data->map[y][x - 1] == '1')
						data->map[y][x] = '1';
			}
			x++;
		}
		y++;
	}
}
