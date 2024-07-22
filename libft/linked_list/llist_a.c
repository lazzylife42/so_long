/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:53:08 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/19 15:01:37 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_Cell	*create_cell(int data)
{
	t_Cell	*cell;

	cell = malloc(sizeof(cell));
	if (!cell)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
	return (cell);
}

void	set_at(t_List *list, int data, int pos)
{
	int	i;

	i = 0;
	if (is_emplty_list(list))
		printf("La liste est vide\n");
	while (i < pos)
	{
		i++;
		list = list->next;
	}
	list->data = data;
}

void	print_list(t_List *list)
{
	while (list)
	{
		printf("[%d] -> ", list->data);
		list = list->next;
	}
	printf("\n");
}

int	is_emplty_list(t_List *list)
{
	return (list == NULL);
}

int	get_at(t_List *list, int pos)
{
	int	i;

	i = 0;
	if (is_emplty_list(list))
	{
		printf("La liste est vide\n");
		return (-1);
	}
	while (i < pos)
	{
		i++;
		list = list->next;
	}
	return (list->data);
}
