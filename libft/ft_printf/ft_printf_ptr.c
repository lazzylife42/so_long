/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:08:12 by smonte-e          #+#    #+#             */
/*   Updated: 2023/08/13 18:35:28 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ptr(unsigned long ptr)
{
	int		len;
	char	*str;

	len = ft_printf_str("0x");
	if (ptr == 0)
		len += ft_printf_char('0');
	else
	{
		str = ft_ulltoa_base(ptr, "0123456789abcdef");
		if (!str)
			return (0);
		len += ft_printf_str(str);
		free(str);
	}
	return (len);
}
