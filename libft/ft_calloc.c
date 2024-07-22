/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:17:54 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/12 12:50:54 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb_elem, size_t size_elem)
{
	void			*ptr;
	size_t			i;
	unsigned char	c;

	ptr = malloc(nb_elem * size_elem);
	if (!ptr)
		return (NULL);
	i = 0;
	c = '\0';
	while (i < (nb_elem * size_elem))
	{
		((char *)ptr)[i] = c;
		i++;
	}
	return (ptr);
}
