/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:28:15 by kade-sou          #+#    #+#             */
/*   Updated: 2023/06/16 13:20:31 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trimfree(char *s1, char const *set)
{
	char	*rec;
	size_t	i;
	size_t	h;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	h = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
	{
		i++;
	}
	while (ft_strchr(set, s1[h]) && h > 0)
	{
		h--;
	}
	h++;
	rec = ft_substr(s1, i, h - i);
	free(s1);
	return (rec);
}
