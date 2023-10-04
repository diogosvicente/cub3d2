/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:12:04 by kade-sou          #+#    #+#             */
/*   Updated: 2022/06/21 13:35:06 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst != NULL || src != NULL)
	{
		while (n--)
		{
			*(unsigned char *)(dst + n) = *(unsigned char *)(src + n);
		}
		return (dst);
	}	
	return (NULL);
}
