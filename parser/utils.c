/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:40:21 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/20 15:55:43 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	lentab(char *line, char c)
{
	int	count;

	if (!line)
		return (0);
	count = 0;
	while (*line)
	{
		if (*line == c)
			count++;
		line++;
	}
	return (count);
}

void	cleaning(t_all *all)
{
	if (all->no.path)
		free(all->no.path);
	if (all->so.path)
		free(all->so.path);
	if (all->ea.path)
		free(all->we.path);
	if (all->we.path)
		free(all->ea.path);
}

void	clear_map(char **map)
{
	int	i;

	i = 0;
	while(map[i])
		free(map[i++]);
	free(map);
}
