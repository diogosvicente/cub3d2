/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:29:25 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/30 18:28:28 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_all	all;

	ft_memset(&all, 0, sizeof(t_all));
	if (argc != 2)
	{
		printf("Error\n\tNumber of Arguments\n");
		return (42);
	}
	all.color_fl = 0;
	all.color_cl = 0;
	check_cub(argv[1]);
	fd = check_fd(argv[1]);
	check_file(fd, &all, 0);
	if (is_map_okay(&all) == -1)
	{
		cleaning(&all);
		return (42);
	}
	render_game(&all);
}
