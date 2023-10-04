/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 22:50:31 by kade-sou          #+#    #+#             */
/*   Updated: 2022/11/30 18:53:00 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsignbr(unsigned int n)
{
	unsigned int	div;
	unsigned int	mod;
	int				c;

	c = 0;
	div = n / 10;
	mod = n % 10;
	if (div > 0)
		c += ft_unsignbr(div);
	c += ft_putchar(mod + '0');
	return (c);
}
