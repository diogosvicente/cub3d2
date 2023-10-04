/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:38:07 by kade-sou          #+#    #+#             */
/*   Updated: 2022/06/21 17:17:31 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst != NULL || src != NULL)
	{
		if (dst > src)
			ft_memcpy(dst, src, len);
		if (dst < src)
		{
			while (len--)
			{
				*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
				i++;
			}
		}
		return (dst);
	}
	return (NULL);
}
