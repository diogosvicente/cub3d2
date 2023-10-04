/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:56:02 by kade-sou          #+#    #+#             */
/*   Updated: 2022/11/30 19:05:02 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_swcase(char ch, va_list all)
{
	int	hurb;

	hurb = 0;
	if (ch == 'c')
		hurb += ft_putchar(va_arg(all, int));
	else if (ch == 's')
		hurb += ft_putstr(va_arg(all, char *));
	else if (ch == 'p')
	{
		hurb += write(1, "0x", 2);
		hurb += ft_hexnbr(va_arg(all, long long int), 'x');
	}
	else if (ch == 'd' || ch == 'i')
		hurb += ft_putnbr(va_arg(all, int));
	else if (ch == '%')
		hurb += ft_putchar('%');
	else if (ch == 'x' || ch == 'X')
		hurb += ft_hexnbr(va_arg(all, unsigned int), ch);
	else if (ch == 'u')
		hurb += ft_unsignbr(va_arg(all, unsigned int));
	return (hurb);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		cnt;
	va_list	al;

	va_start(al, s);
	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			cnt += ft_swcase(s[++i], al);
			i++;
		}
		else
		{
		cnt += write(1, &s[i], 1);
		i++;
		}
	}
	va_end(al);
	return (cnt);
}
