/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_modified.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:10:52 by dioda-si          #+#    #+#             */
/*   Updated: 2022/12/06 16:22:12 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_modified(char *s)
{
	int	index;

	index = 0;
	if (!s)
		return (write (1, "(null)", 6));
	while (s[index] != '\0')
	{
		ft_putchar_modified(s[index]);
		index++;
	}
	return (index);
}
