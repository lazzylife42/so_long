/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:43:42 by smonte-e          #+#    #+#             */
/*   Updated: 2022/12/07 22:34:57 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	else if (n == 0)
		len++;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	size_t	i;

	number = n;
	i = ft_intlen(number);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (number < 0)
	{
		number *= -1;
		str[0] = '-';
	}
	str[i--] = '\0';
	if (number == 0)
		str[i] = '0';
	while (number > 0)
	{
		str[i--] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}
