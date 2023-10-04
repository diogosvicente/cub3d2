/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:18:30 by kade-sou          #+#    #+#             */
/*   Updated: 2022/06/30 16:17:04 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp;

	temp = (char *)s;
	while (n--)
	{
		if (*temp == (char) c)
		{
			return ((void *)temp);
		}
		temp++;
	}
	return (NULL);
}
