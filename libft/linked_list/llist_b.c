/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:53:38 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/19 15:00:20 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

long	len_list(t_List *list)
{
	long	len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

t_List	*empty_list(void)
{
	return (NULL);
}

t_List	*add_at(t_List *list, int data, int pos)
{
	int		i;
	t_List	*prec;
	t_List	*cur;
	t_Cell	*cell;

	prec = list;
	cur = list;
	cell = create_cell(data);
	if (is_emplty_list(list))
		return (cell);
	if (pos == 0)
	{
		cell->next = list;
		return (cell);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cell;
	cell->next = cur;
	return (list);
}

t_List	*add_end(t_List *list, int data)
{
	t_Cell	*cell;
	t_List	*cur;

	cell = create_cell(data);
	if (!cell)
		return (list);
	if (!list)
		return (cell);
	cur = list;
	while (cur->next)
		cur = cur->next;
	cur->next = cell;
	return (list);
}

t_List	*free_at(t_List *list, int pos)
{
	int		i;
	t_List	*prec;
	t_List	*cur;

	prec = list;
	cur = list;
	if (is_emplty_list(list))
		return (NULL);
	if (pos == 0)
	{
		list = list->next;
		free(cur);
		return (list);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		prec = cur;
		cur = cur->next;
	}
	prec->next = cur->next;
	free(cur);
	return (list);
}
