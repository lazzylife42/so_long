/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:51:51 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/12 12:55:36 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *buff, size_t end)
{
	char	*str;
	size_t	i;

	str = (char *)ft_calloc(end + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= end && buff[i])
	{
		str[i] = buff[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
