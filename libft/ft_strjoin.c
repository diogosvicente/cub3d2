/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:43:59 by kade-sou          #+#    #+#             */
/*   Updated: 2022/06/30 15:46:53 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		i1;
	char	*rec;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	i1 = ft_strlen(s1);
	rec = malloc(i1 + ft_strlen(s2) + 1);
	if (!rec)
		return (NULL);
	ft_memcpy(rec, s1, i1);
	while (s2[i] != '\0')
	{
		rec[i1 + i] = s2[i];
		i++;
	}
	rec[i1 + i] = '\0';
	return (rec);
}
