/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:45:56 by kade-sou          #+#    #+#             */
/*   Updated: 2022/06/30 16:18:20 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	count(long int n)
{
	int	x;

	x = 0;
	if (n <= 0)
	{
		n = n * -1;
		x++;
	}
	while (n > 0)
	{
		n = n / 10;
		x++;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	int			c;
	long int	h;
	char		*rec;

	h = n;
	c = count(h);
	rec = malloc(c + 1);
	if (!rec)
		return (NULL);
	if (h == 0)
		rec[0] = '0';
	if (h < 0)
	{
		rec[0] = '-';
		h = h * -1;
	}
	rec[c] = '\0';
	while (h > 0)
	{
		c--;
		rec[c] = 48 + (h % 10);
		h = h / 10;
	}
	return (rec);
}
