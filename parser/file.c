/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:44:04 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/09 17:40:40 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	check_color(char *line, const char *dir, int *ref)
{
	char	*sav;
	char	*color;

	(void)ref;
	sav = ft_strnstr(line, dir, ft_strlen(line));
	color = ft_strtrim(sav + 2, " ");//sem espaço \t \v \r \f ? 
	
	return (1);
}

int	check_line(char *line, t_all *all)
{
	int	size;
	int	flag;

	flag = 0;
	size = ft_strlen(line);
	if (ft_strnstr(line, "NO ", size))
		flag = check_text(line, "NO ", &all->no);
	else if (ft_strnstr(line, "SO ", size))
		flag = check_text(line, "SO ", &all->so);
	else if (ft_strnstr(line, "WE ", size))
		flag = check_text(line, "WE ", &all->we);
	else if (ft_strnstr(line, "EA ", size))
		flag = check_text(line, "EA ", &all->ea);
	else if (ft_strnstr(line, "F ", size))
		flag = check_color(line, "F ", &all->color_fl);
	else if (ft_strnstr(line, "C ", size))
		flag = check_color(line, "C ", &all->color_cl);
//	else
//		flag = check_map(line, all->map);
	return (flag);
}

void	check_file(int fd, t_all *all)
{
	int	flag;
	char	*res;

	while (TRUE)
	{
		res = get_next_line(fd);
		if (!res)
			break ;
		flag = check_line(res, all);
		if (flag == -1)
		{
			//limpatudo(all);
			break ;////to do : por enquanto malloc só em path futuramente malloc em map;
		}
	}

}
