/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:41:48 by kade-sou          #+#    #+#             */
/*   Updated: 2022/06/30 15:50:58 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;

	s = ft_strlen(src);
	while (*dst != '\0' && dstsize > 0)
	{
		s++;
		dst++;
		dstsize--;
	}
	while (dstsize >= 1)
	{
		if (*src == '\0' || dstsize == 1)
		{
			*dst = '\0';
			break ;
		}
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	return (s);
}
