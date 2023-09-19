/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:02:28 by dioda-si          #+#    #+#             */
/*   Updated: 2022/12/06 16:21:12 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_treatment(va_list arg, const char str)
{
	int	bytes;

	bytes = 0;
	if (str == 'c')
		bytes = bytes + ft_putchar_modified(va_arg(arg, int));
	else if (str == 's')
		bytes = bytes + ft_putstr_modified(va_arg(arg, char *));
	else if (str == 'd' || str == 'i')
		bytes = bytes + ft_putnbr_modified(va_arg(arg, int));
	else if (str == '%')
		bytes = bytes + ft_putchar_modified(str);
	else if (str == 'u')
		bytes = bytes + ft_unsigned(va_arg(arg, unsigned int));
	else if (str == 'x' || str == 'X')
		bytes = bytes + ft_hex(va_arg(arg, unsigned int), str);
	else
		bytes = bytes + (ft_0x() + ft_pointer(va_arg(arg, unsigned long)));
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	int		index;
	int		sum_bytes;
	va_list	arg;

	index = 0;
	sum_bytes = 0;
	va_start (arg, str);
	while (str[index] != '\0')
	{
		if (str[index] == '%' && ft_strchr("cspdiuxX%", str[index + 1]))
			sum_bytes = sum_bytes + ft_treatment(arg, str[1 + index++]);
		else
			sum_bytes = sum_bytes + ft_putchar_modified(str[index]);
		index++;
	}
	va_end(arg);
	return (sum_bytes);
}
