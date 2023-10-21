/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:49:59 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/20 15:55:42 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cubed.h"

int	check_map(char *buff_map)
{
	int	i;
	int	pos;

	pos = 0;
	i = -1;
	while (buff_map[++i])
	{
		if (ft_strchr("NWES", buff_map[i]))
			pos++;
		if (!ft_strchr(" \t01NWSE&", buff_map[i]))
		{
			printf("Error\n Invalid Char MAP\n");
			free(buff_map);
			return (-1);
		}
	}
	if (pos != 1)
	{
		printf("Error\n More/Less then 1 init pos\n");
		free(buff_map);
		return (-1);
	}
	return (1);
}

char	**final_map(char *buff_map)
{
	char	**ret;

	if (!buff_map)
		return (NULL);
	if (check_map(buff_map) == -1)
		return (NULL);
	ret = ft_split(buff_map, '&');
	free(buff_map);
	return (ret);
}

char	*concat_map(char *line, char *buff)
{
	char	*aux;
	char	*ret;

	if (line[0] != '\n')
		aux = ft_strtrim(line, "\n");
	else
		aux = ft_strdup(line);
	aux = ft_joinfree(aux, "&");
	ret = ft_strjoin(buff, aux);
	if (buff[0])
		free(buff);
	free(aux);
	return (ret);
}

int	start_map(char *line, int start)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (start == 1)
		return (1);
	while(ft_isspace(line[i]))
			i++;
	if (line[i] == '\0')
		return (0);
	while (line[i])
	{
		while (line[i] == '1' && line[i++])
			count++;
		if (line[i] == '\n' && line [i + 1] == '\0')
			i++;
		if (line[i] != '1' && !ft_isspace(line[i]) && line[i])
			return (0);
		i++;
	}
	if (count < 3)
		return (0);
	return (1);
}
