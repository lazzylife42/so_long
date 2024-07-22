/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:59:10 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/02 15:59:33 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	int	get_texture_index(char cell)
{
	if (cell == '1')
		return (2);
	else if (cell == '0')
		return (3);
	else if (cell == 'P')
		return (0);
	else if (cell == 'C')
		return (1);
	else if (cell == 'E')
		return (4);
	else if (cell == 'B')
		return (5);
	return (0);
}

void	map_renderer(t_data *data)
{
	int		x;
	int		y;
	int		texture_index;
	char	*str;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			texture_index = get_texture_index(data->map[y][x]);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->textures[texture_index], x * 64, y * 64);
			x++;
		}
		y++;
	}
	move_booba(data);
	str = ft_itoa(data->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 23, 19,
		0xffffff, str);
	free(str);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	data = NULL;
}

void	p_data(t_data *data)
{
	ft_printf("\nimg : %p\n"
		"adr0: %p\nadr1: %p\nadr2: %p\nadr3: %p\nadr4: %p\nadr5: %p\n"
		"mlx : %p\nwin : %p\n"
		"tex0: %p\ntex1: %p\ntex2: %p\ntex3: %p\ntex4: %p\ntex5: %p\n"
		"map : %p\n"
		"text: %p\n\n",
		data->img, data->addr[0], data->addr[1], data->addr[2], data->addr[3],
		data->addr[4], data->addr[5], data->mlx_ptr, data->win_ptr,
		data->textures[0], data->textures[1], data->textures[2],
		data->textures[3], data->textures[4], data->textures[5], data->map,
		data->textures);
}
