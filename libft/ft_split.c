/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:01:35 by kade-sou          #+#    #+#             */
/*   Updated: 2022/06/30 15:43:01 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	count(const char *s, char c)
{
	size_t	p;
	size_t	i;
	size_t	st;

	p = 0;
	i = 0;
	while (s[p] != '\0')
	{
		while (s[p] == c && s[p] != '\0')
			p++;
		st = p;
		while (s[p] != c && s[p] != '\0')
			p++;
		if (st != p)
			i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	x;
	size_t	y;
	size_t	st;
	char	**rec;

	if (!s)
		return (NULL);
	x = 0;
	y = 0;
	rec = ft_calloc((count(s, c) + 1), sizeof(char *));
	if (!rec)
		return (NULL);
	while (s[x] != '\0')
	{
		while (s[x] == c && s[x] != '\0')
			x++;
		st = x;
		while (s[x] != c && s[x] != '\0')
			x++;
		if (st != x)
			rec[y] = ft_substr(s, st, x - st);
		y++;
	}
	return (rec);
}
