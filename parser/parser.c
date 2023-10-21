/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:10:32 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/20 15:55:42 by kade-sou         ###   ########.fr       */
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

/*int	main(int argc, char **argv)
{
	int		fd;
	t_all	all;

	if (argc != 2)
	{
		printf("Error\n Wrong arguments\n");
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
		return (44);
	}
	//////// limpando o que eu "preciso" ///////
	printf("NO %s\n", all.no.path);
	printf("SO %s\n", all.so.path);
	printf("WE %s\n", all.we.path);
	printf("EA %s\n", all.ea.path);
	printf("F aqui %d\n", all.color_fl);
	printf("C aqui %d\n", all.color_cl);
	int i;
	if (all.map){
	for (i = 0; all.map[i] ; i++){
		printf("->%s<-\n", all.map[i]);
		free(all.map[i]);
	}}
	printf("Index -> %d vs Rows %d\n", i, all.rows);
	printf("COL %d\n", all.cols);
	free(all.map);
	free(all.no.path);
	free(all.so.path);
	free(all.we.path);
	free(all.ea.path);
	close(fd);
}*/
