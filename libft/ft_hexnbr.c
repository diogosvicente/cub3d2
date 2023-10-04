/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:07:19 by kade-sou          #+#    #+#             */
/*   Updated: 2022/11/30 18:57:44 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexnbr(size_t n, char ch)
{
	char	*base;
	int		c;

	c = 0;
	if (ch == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < 16)
	{
		c += write(1, &base[n], 1);
	}
	else
	{
		c += ft_hexnbr(n / 16, ch);
		c += ft_hexnbr(n % 16, ch);
	}
	return (c);
}
