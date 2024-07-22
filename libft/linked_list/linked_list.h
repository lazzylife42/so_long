/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:53:56 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/19 15:46:33 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LINKED_LIST_H
# define LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct t_Cell
{
	int				data;
	struct t_Cell	*next;
}t_List,	t_Cell;

//	llist_a.c 

t_Cell	*create_cell(int data);
void	set_at(t_List *list, int data, int pos);
void	print_list(t_List *list);
int		is_emplty_list(t_List *list);
int		get_at(t_List *list, int pos);

//	llist_b.c

long	len_list(t_List *list);
t_List	*empty_list(void);
t_List	*add_at(t_List *list, int data, int pos);
t_List	*add_end(t_List *list, int data);
t_List	*free_at(t_List *list, int pos);

//	llist_c.c

t_List	*free_list(t_List *list);

#endif
