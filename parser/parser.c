/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:10:32 by kade-sou          #+#    #+#             */
/*   Updated: 2023/11/01 15:59:53 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n Non-existent file: %s\n", file);
		exit(44);
	}
	return (fd);
}

void	check_cub(char *arg)
{
	const char	*cub = ".cub";
	char		*sav;
	int			len;

	len = ft_strlen(arg);
	sav = arg + len - 4;
	while (*cub)
	{
		if (*cub != *sav)
		{
			printf("Error\n Extension .cub\n");
			exit(43);
		}
		cub++;
		sav++;
	}
}
