/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:41:29 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/09 10:33:44 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	check_textfd(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n Path not found: %s\n", path);
		return (-1);
	}
	close(fd);
	return (1);
}

int	check_text(char *line, const char *dir, t_text *ref)
{
	char	*sav;
	int	len;

	sav = ft_strnstr(line, dir, ft_strlen(line));
	ref->path = ft_strtrim(sav + 3, " ");//sem espaço \t \v \r \f ? 
	sav = ref->path;
	len = ft_strlen(sav) - 4;
	while (*(sav + len))
	{
		if (ft_strchr(".xpm", *sav))
		{
			printf("Error\n Extension .xpm: %s\n", ref->path);
			return (-1);
		}
		sav++;
	}
	if (check_textfd(ref->path) == -1)
		return (-1);
	return (1);
}
