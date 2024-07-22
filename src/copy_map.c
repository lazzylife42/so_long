/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:41:24 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/01 15:53:24 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	t_data	*init_copy(const t_data *source)
{
	t_data	*copy;

	copy = (t_data *)malloc(sizeof(t_data));
	if (copy == NULL)
		return (NULL);
	copy->map_width = source->map_width;
	copy->map_height = source->map_height;
	return (copy);
}

static	char	**allocate_map(int height, int width)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(height * sizeof(char *));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		map[i] = (char *)malloc(width * sizeof(char));
		if (map[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(map[j]);
				j++;
			}
			free(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

void	copy_map(char **dest, const char **source, int height, int width)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			dest[y][x] = source[y][x];
			x++;
		}
		y++;
	}
}

t_data	*copy_data(const t_data *source)
{
	t_data	*copy;

	copy = init_copy(source);
	if (copy == NULL)
		return (NULL);
	copy->map = allocate_map(source->map_height, source->map_width);
	if (copy->map == NULL)
	{
		free(copy);
		return (NULL);
	}
	copy_map(copy->map, (const char **)source->map,
		source->map_height, source->map_width);
	return (copy);
}
