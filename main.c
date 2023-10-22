/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:29:25 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/20 15:39:59 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_all	all;

	if (argc != 2)
	{
		printf("Error\n\tNumber of Arguments\n");
		return (42);
	}
	all.color_fl = 0;
	all.color_cl = 0;
	check_cub(argv[1]);
	fd = check_fd(argv[1]);
	check_file(fd, &all);
	if (is_map_okay(&all) == -1)
	{
		cleaning(&all);
		return (42);
	}
	render_game(&all);
}
