/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:38:22 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/02 13:06:58 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	on_destroy(t_data *data)
{
	free_map(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	off_destroy(t_data *data)
{
	free_map(data);
	exit(EXIT_FAILURE);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_error	error;

	if (argc != 2)
	{
		write(2, "Error\nNombre d'arguments incorrect.\n", 36);
		exit(EXIT_FAILURE);
	}
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	map_renderer_init(&data, argv);
	error_check(&error, &data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, (data.map_width) * 64,
			(data.map_height) * 64, "Les Singes Viennent de Sortir du Zoo");
	if (!data.win_ptr)
		off_destroy(&data);
	data.moves = 0;
	map_renderer(&data);
	mlx_hook(data.win_ptr, 3, 0, &player_move, &data);
	mlx_hook(data.win_ptr, 17, 0, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
