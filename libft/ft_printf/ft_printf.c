/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:19:37 by smonte-e          #+#    #+#             */
/*   Updated: 2023/09/18 17:40:18 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_printf_conv(format[i], ap);
		}
		else
			len += ft_printf_char(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

int	ft_printf_conv(char format, va_list ap)
{
	if (format == '%')
		return (ft_printf_char('%'));
	else if (format == 'c')
		return (ft_printf_char(va_arg(ap, int)));
	else if (format == 's')
		return (ft_printf_str(va_arg(ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_printf_n_base(va_arg(ap, int), "0123456789"));
	else if (format == 'u')
		return (ft_printf_ui(va_arg(ap, unsigned int)));
	else if (format == 'x')
		return (ft_printf_n_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_printf_n_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (format == 'p')
		return (ft_printf_ptr((unsigned long)va_arg(ap, void *)));
	return (0);
}
