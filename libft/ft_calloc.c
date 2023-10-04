/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:21:35 by kade-sou          #+#    #+#             */
/*   Updated: 2022/06/30 16:22:01 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rec;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1 ;
	}
	rec = malloc(count * size);
	if (!rec)
		return (NULL);
	ft_bzero (rec, count * size);
	return (rec);
}
