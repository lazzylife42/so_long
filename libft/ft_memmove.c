/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:55:53 by smonte-e          #+#    #+#             */
/*   Updated: 2022/12/07 22:38:30 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;
	size_t	i;

	temp = (char *)src;
	i = 0;
	if ((char *)dst == temp)
		return (dst);
	else if ((char *)dst > temp)
		while (len-- > 0)
			((char *)dst)[len] = temp[len];
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = temp[i];
			i++;
		}
	}
	return (dst);
}
