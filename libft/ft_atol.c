/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:17:09 by sab               #+#    #+#             */
/*   Updated: 2023/10/09 15:53:50 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int		i;
	int		signe;
	long	cache;

	i = 0;
	signe = 1;
	cache = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
		if (str[i] == '+' || str[i] == '-')
			return (0);
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		cache = cache * 10 + (str[i] - 48);
		i++;
	}	
	return (signe * cache);
}
