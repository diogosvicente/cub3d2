/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:09:06 by dioda-si          #+#    #+#             */
/*   Updated: 2022/11/26 11:48:20 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i_dst;
	size_t	i_src;

	if (dstsize == 0)
		return (ft_strlen(src));
	i_dst = 0;
	i_src = 0;
	while (dst[i_dst] != '\0' && i_dst < dstsize)
		i_dst++;
	while (src[i_src] != '\0' && (i_dst + i_src + 1) < dstsize)
	{
		dst[i_dst + i_src] = src[i_src];
		i_src++;
	}
	if (i_dst < dstsize)
		dst[i_dst + i_src] = '\0';
	return (i_dst + ft_strlen(src));
}
