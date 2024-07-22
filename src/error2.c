/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:53:58 by smonte-e          #+#    #+#             */
/*   Updated: 2023/11/02 16:18:27 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_counts(int *p, int *e, int *c)
{
	*p = 0;
	*e = 0;
	*c = 0;
}

static	void	count_elements(int *p, int *e, int *c, char cell)
{
	if (cell == 'P')
		(*p) += 1;
	else if (cell == 'E')
		(*e) += 1;
	else if (cell == 'C')
		(*c) += 1;
}

void	error_elements(t_error *error, t_data *data)
{
	int	x;
	int	y;
	int	p;
	int	e;
	int	c;

	init_counts(&p, &e, &c);
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			count_elements(&p, &e, &c, data->map[y][x]);
			x++;
		}
		y++;
	}
	if (p != 1 || e != 1 || c == 0)
		error->bad_map = TRUE;
}

void	error_check(t_error *error, t_data *data)
{
	t_data	*cp;

	error_init(error);
	error_elements(error, data);
	if (error->bad_map)
		write(2, "Error\nLa carte ne dispose pas des éléments correctes.\n", 55);
	error_empty(error, data);
	if (error->empty)
		write(2, "Error\nLa carte ne peut etre vide.\n", 34);
	error_square(error, data);
	if (error->square)
		write(2, "Error\nLa carte doit être de forme rectangulaire.\n", 50);
	error_size(error, data);
	if (error->walls)
		write(2, "Error\nLa carte doit être encadrée par des murs.\n", 50);
	if (error->overflow)
		write(2, "Error\nLes dimentions des la carte sont trop grandes.\n", 53);
	if (error->bad_char)
		write(2, "Error\nLa carte est corrompue.\n", 30);
	cp = copy_data(data);
	error_path(error, cp);
	if (error->v_path)
		write(2, "Error\nIl néxiste pas de chemin valide.\n", 40);
	free_map(cp);
	error_exit(error, data, cp);
}

void	error_exit(t_error *error, t_data *data, t_data *cp)
{
	free(cp);
	if (error->empty || error->square || error->walls
		|| error->overflow || error->v_path || error->bad_char
		|| error->bad_map)
	{
		ft_printf("\n\n[%d][%d][%d][%d][%d][%d][%d]\n",
			error->empty, error->square, error->walls,
			error->overflow, error->bad_char,
			error->bad_map, error->v_path);
		off_destroy(data);
	}
}
