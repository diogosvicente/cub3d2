/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 16:38:22 by kade-sou          #+#    #+#             */
/*   Updated: 2022/12/06 16:50:14 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*rec;

	i = 0;
	rec = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!rec)
		return (NULL);
	while (s1[i] != '\0')
	{
		rec[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		rec[j + i] = s2[j];
		j++;
	}
	free(s1);
	return (rec);
}
