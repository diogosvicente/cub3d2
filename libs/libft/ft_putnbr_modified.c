/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_modified.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:19:09 by dioda-si          #+#    #+#             */
/*   Updated: 2022/12/06 16:22:39 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_modified(int n)
{
	char	*str;
	int		nlen;

	str = ft_itoa(n);
	nlen = ft_putstr_modified(str);
	free (str);
	return (nlen);
}
