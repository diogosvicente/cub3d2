/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:04:39 by kade-sou          #+#    #+#             */
/*   Updated: 2022/06/30 15:53:29 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*rec;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	rec = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!rec)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		rec[i] = f(i, s[i]);
		i++;
	}
	return (rec);
}
