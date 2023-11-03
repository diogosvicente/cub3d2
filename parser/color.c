/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:10:50 by kade-sou          #+#    #+#             */
/*   Updated: 2023/11/01 15:25:03 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_col(char *sav)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (sav[i])
	{
		if (sav[i] == ',' || (sav[i] == ',' && ft_isdigit(sav[i + 1])))
			count++;
		if (sav[i] != ',' && !ft_isdigit(sav[i]))
		{
			printf("Error\n Color line %s\n", sav);
			free(sav);
			return (-1);
		}
		i++;
	}
	if (count != 2)
	{
		printf("Error\n Count Comma %s\n", sav);
		free(sav);
		return (-1);
	}
	return (1);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	build_color(char *line, const char *dir, t_all *all)
{
	char	**colors;
	int		col[3];
	int		i;

	colors = ft_split(line, ',');
	col[0] = ft_atoi(colors[0]);
	col[1] = ft_atoi(colors[1]);
	col[2] = ft_atoi(colors[2]);
	free(line);
	i = -1;
	while (colors[++i])
		free(colors[i]);
	free(colors);
	if (col[0] > 255 || col[1] > 255 || col[2] > 255)
	{
		printf("Error\n Color bigger than 255 \n");
		return (-1);
	}
	if (dir[0] == 'F')
		all->color_fl = create_trgb(0, col[0], col[1], col[2]);
	else
		all->color_cl = create_trgb(0, col[0], col[1], col[2]);
	return (1);
}

int	check_color(char *line, const char *dir, t_all *all)
{
	const char	*space = " \n\t\v\r\f";
	char		*sav;
	char		*skip;

	sav = ft_strtrim(line, space);
	if (sav[0] != dir[0] || !ft_isspace(sav[1]))
	{
		free(sav);
		return (-1);
	}
	skip = ft_strjoin(space, dir);
	sav = ft_trimfree(sav, skip);
	free(skip);
	if (check_col(sav) == -1)
		return (-1);
	if (build_color(sav, dir, all) == -1)
		return (-1);
	return (1);
}
