/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:24:45 by kade-sou          #+#    #+#             */
/*   Updated: 2022/06/30 16:13:26 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*rec;
	size_t	x;

	x = ft_strlen(s1);
	rec = malloc(sizeof(char) * (x + 1));
	if (!rec)
		return (NULL);
	ft_memcpy(rec, s1, x);
	rec[x] = '\0';
	return (rec);
}
