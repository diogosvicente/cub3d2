/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:41:10 by kade-sou          #+#    #+#             */
/*   Updated: 2023/11/01 16:00:23 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

void	flood(char **map, int y, int x, t_all *all)
{
	int	rows;
	int	cols;

	rows = all->rows + 2;
	cols = all->cols + 2;
	{
		if ((x < 0 || y < 0 || x >= cols || y >= rows)
			|| (map[y][x] != ' ' && map[y][x] != '0'))
			return ;
		if (map[y][x] == '0')
		{
			printf("Error\n Map opened\n");
			clear_map(map);
			clear_map(all->map);
			cleaning(all);
			exit(42);
		}
		map[y][x] = '2';
		flood(map, y + 1, x, all);
		flood(map, y, x + 1, all);
		flood(map, y - 1, x, all);
		flood(map, y, x - 1, all);
	}
}

char	*fix_size(char *line, int size)
{
	char	*aux;
	char	*aux2;
	int		res;

	res = size - ft_strlen(line);
	aux = ft_calloc(sizeof(char *), res + 1);
	if (!aux)
		return (line);
	aux2 = ft_strjoin(" ", line);
	ft_memset(aux, ' ', res);
	aux2 = ft_joinfree(aux2, aux);
	free(aux);
	return (aux2);
}

char	**map_for_validation(char **map, int cols, int rows)
{
	int		i;
	char	**aux;
	char	*space;

	i = 0;
	if (!map)
		return (NULL);
	aux = ft_calloc(sizeof(char *), rows + 3);
	if (!aux)
		return (NULL);
	space = ft_calloc(sizeof(char *), cols + 2);
	ft_memset(space, ' ', cols + 2);
	aux[0] = ft_strdup(space);
	while (map[i])
	{
		aux[i + 1] = fix_size(map[i], cols + 1);
		i++;
	}
	aux[i + 1] = ft_strdup(space);
	free(space);
	return (aux);
}
