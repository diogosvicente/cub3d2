/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:25:57 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/20 15:55:43 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

char	*fix_tab(char *line)
{
	char	*aux;
	int		num_tab;
	int		i;
	int		j;

	j = 0;
	i = -1;
	num_tab = lentab(line, '\t');
	aux = malloc((num_tab * 8) + ft_strlen(line) - num_tab + 1);
	if (!aux)
		return (line);
	while (line[++i])
	{
		if (line[i] == '\t')
		{
			ft_memset(aux + j, ' ', 8);
			j += 7;
		}
		else
			aux[j] = line[i];
		j++;
	}
	aux[j] = '\0';
	free(line);
	return (aux);
}

char	**tab_size(char **map, t_all *all)
{
	int	i;
	int	new_size;
	int	old_size;

	new_size = 0;
	old_size = 0;
	i = -1;
	while (map[++i])
	{
		if (ft_strchr(map[i], '\t'))
			map[i] = fix_tab(map[i]);
		if (ft_strchr(map[i], '\t'))
		{
			printf("Porra malloc, tem vazamento\n");
			clear_map(map);
			return (NULL);
		}
		new_size = ft_strlen(map[i]);
		if (new_size > old_size)
			old_size = new_size;
	}
	all->cols = old_size;
	all->rows = i;
	return (map);
}

void	rect_map(char **map, t_all *all)
{
	int		i;
	int		len;
	char	*aux;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len < all->cols)
		{
			aux = ft_calloc(sizeof(char), all->cols - len + 1);
			ft_memset(aux, ' ', all->cols - len);
			map[i] = ft_joinfree(map[i], aux);
			free(aux);
		}
		i++;
	}
}

int	is_map_okay(t_all *all)
{
	char	**map2;

	if (!all->map)
		return (-1);
	all->map = tab_size(all->map, all);
	if (!all->map)
		return (-1);
	rect_map(all->map, all);
	map2 = map_for_validation(all->map, all->cols, all->rows);
	if (!map2)
	{
		clear_map(all->map);
		return (-1);
	}
	flood(map2, 0, 0, all);
	clear_map(map2);
	return (1);
}
