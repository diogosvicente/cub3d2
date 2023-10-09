/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:10:32 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/09 17:41:54 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

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
	int		len;
	
	len = ft_strlen(arg);
	sav = arg + len - 4;
	printf("\n");
	while(*cub)
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

int	main(int argc, char **argv)
{
	int	fd;
	t_all	all;

	if (argc != 2)
	{
		printf("Error\n Wrong arguments\n");
		exit(42);
	}

	//printf("%d\n", ft_strlen("       "));
	check_cub(argv[1]);
	fd = check_fd(argv[1]);
	check_file(fd, &all);
}
