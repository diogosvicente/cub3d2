/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:32:57 by kade-sou          #+#    #+#             */
/*   Updated: 2023/02/10 17:05:24 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chrinbase(char c, int len)
{
	char	*base;
	char	*base2;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	while (i < len)
	{
		if (c == base[i] || c == base2[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sig;
	int	num;

	i = 0;
	sig = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sig *= -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (chrinbase(str[i], str_base))
	{
		num = num * str_base + chrinbase(str[i], str_base);
		i++;
	}
	return (num * sig);
}
