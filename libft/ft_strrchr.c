/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:31:38 by smonte-e          #+#    #+#             */
/*   Updated: 2022/11/29 00:12:24 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <sting.h>
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*new;

	i = ft_strlen(s);
	new = (char *)s;
	while (new[i] != (char)c && i != 0)
		i--;
	if (new[i] != (char)c)
		return (NULL);
	else
		return (&new[i]);
}
