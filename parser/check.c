/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:41:29 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/31 17:57:27 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

static int	check_textfd(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n Path not found: %s\n", path);
		free(path);
		return (-1);
	}
	close(fd);
	return (1);
}

int	check_xpm(char *sav)
{
	int	len;
	int	i;

	i = -1;
	while (sav[++i])
	{
		if (ft_isspace(sav[i]))
		{
			printf("Error\n Path Wrong -> %s\n", sav);
			free(sav);
			return (-1);
		}
	}
	len = ft_strlen(sav) - 4;
	while (sav[len])
	{
		if (!ft_strchr(".xpm", sav[len]))
		{
			printf("Error\n Extension .xpm: %s\n", sav);
			free(sav);
			return (-1);			printf("Error\n Path Wrong -> %s\n", sav);

		}
		len++;
	}
	return (1);
}

int	check_text(char *line, const char *dir, t_text *ref)
{
	const char	*space = " \n\t\v\r\f";
	char		*sav;
	char		*skip;

	sav = ft_strtrim(line, space);
	if (sav[0] != dir[0] || sav[1] != dir[1] || !ft_isspace(sav[2]))
	{
		free(sav);
		return (-1);
	}
	skip = ft_strjoin(space, dir);
	sav = ft_trimfree(sav, skip);
	free(skip);
	if (check_xpm(sav) == -1)
		return (-1);
	if (check_textfd(sav) == -1)
		return (-1);
	ref->path = ft_strdup(sav);
	free(sav);
	return (1);
}
