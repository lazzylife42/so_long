/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:12:38 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/19 15:48:00 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_str(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			len += ft_printf_char(str[i]);
			i++;
		}
	}
	else
		len = ft_printf_str("(null)");
	return (len);
}

int	ft_printf_ui(unsigned long long number)
{
	int		len;
	char	*str;

	str = ft_ulltoa_base(number, "0123456789");
	if (!str)
		return (0);
	len = ft_printf_str(str);
	free(str);
	return (len);
}

int	ft_printf_n_base(long long number, char *base)
{
	int		baselen;
	int		len;

	baselen = ft_strlen(base);
	len = 0;
	if (number < 0)
	{
		len += ft_printf_char('-');
		len += ft_printf_n_base(number * -1, base);
	}
	else if (number >= baselen)
	{
		len += ft_printf_n_base(number / baselen, base);
		len += ft_printf_n_base(number % baselen, base);
	}
	else
		len += ft_printf_char(base[number]);
	return (len);
}
