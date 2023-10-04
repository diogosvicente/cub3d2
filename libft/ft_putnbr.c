/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:38:08 by kade-sou          #+#    #+#             */
/*   Updated: 2022/11/30 18:55:01 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_putnbr(int n)
{
	int	div;
	int	mod;
	int	c;

	c = 0;
	div = n / 10;
	mod = n % 10;
	if (n < 0)
	{
		c += ft_putchar('-');
		div = div * -1;
		mod = mod * -1;
	}
	if (div > 0)
		c += ft_putnbr(div);
	c += ft_putchar(mod + '0');
	return (c);
}
