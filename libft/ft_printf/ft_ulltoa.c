/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:56:33 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/18 19:32:16 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ullen_base(unsigned long long number, char *base)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number /= ft_strlen(base);
		len++;
	}
	return (len);
}

char	*ft_ulltoa_base(unsigned long long number, char *base)
{
	int		i;
	char	*str;

	i = ft_ullen_base(number, base);
		str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (number <= 0)
		str[i] = 0;
	while (i >= 0)
	{
		str[i--] = base[number % ft_strlen(base)];
		number /= ft_strlen(base);
	}
	return (str);
}
