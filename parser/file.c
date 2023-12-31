/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:44:04 by kade-sou          #+#    #+#             */
/*   Updated: 2023/11/01 15:31:50 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	only_space(char *line)
{
	while (*line)
	{
		if (!ft_strchr(" \n\t\f\v\r", *line))
			return (1);
		line++;
	}
	return (0);
}

int	check_line(char *line, t_all *all)
{
	int	size;
	int	flag;

	flag = 0;
	size = ft_strlen(line);
	if (ft_strnstr(line, "NO", size))
		flag = check_text(line, "NO", &all->no);
	else if (ft_strnstr(line, "SO", size))
		flag = check_text(line, "SO", &all->so);
	else if (ft_strnstr(line, "WE", size))
		flag = check_text(line, "WE", &all->we);
	else if (ft_strnstr(line, "EA", size))
		flag = check_text(line, "EA", &all->ea);
	else if (ft_strnstr(line, "F", size))
		flag = check_color(line, "F", all);
	else if (ft_strnstr(line, "C", size))
		flag = check_color(line, "C", all);
	else if (only_space(line))
	{
		printf("Error\n this line %s", line);
		return (-1);
	}
	return (flag);
}

static void	clean_check_file(t_all *all, char *res, char *buff_map)
{
	cleaning(all);
	free(res);
	free(buff_map);
}

void	check_file(int fd, t_all *all, int start)
{
	char	*res;
	char	*buff_map;

	buff_map = ft_calloc(1, sizeof(char));
	while (TRUE)
	{
		res = get_next_line(fd);
		if (!res)
			break ;
		start = start_map(res, start);
		if (start == 0)
		{
			if (check_line(res, all) == -1)
			{
				clean_check_file(all, res, buff_map);
				exit(0);
			}
		}
		if (start == 1)
			buff_map = concat_map(res, buff_map);
		free(res);
	}
	all->map = final_map(buff_map);
}
