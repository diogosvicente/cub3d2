/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:51:56 by kade-sou          #+#    #+#             */
/*   Updated: 2023/10/14 15:52:26 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*looking_for_next_line(char *finals)
{
	int		h;
	int		t;
	char	*temp;

	h = 0;
	while (finals[h] != '\0' && finals[h] != '\n')
		h++;
	if (finals[h] == '\0')
	{
		free(finals);
		return (NULL);
	}
	t = ft_strlen(finals) - h;
	temp = ft_calloc(t + 1, sizeof(char));
	if (!temp)
	{
		free(finals);
		return (NULL);
	}
	t = 0;
	h++;
	while (finals[h] != '\0')
		temp[t++] = finals[h++];
	free(finals);
	return (temp);
}

static char	*line_is_here(char *finals)
{
	int		i;
	char	*rec;

	i = 0;
	if (finals[i] == '\0')
	{
		free(finals);
		return (NULL);
	}
	while (finals[i] != '\0' && finals[i] != '\n')
		i++;
	rec = ft_calloc((i + 2), sizeof(char *));
	rec = ft_strccpy(rec, finals, i + 2);
	if (finals[i] == '\n')
	{
		rec[i++] = '\n';
	}
	return (rec);
}

static char	*looking_for_line(int fd, char *finals)
{
	char	str[BUFFER_SIZE + 1];
	int		i;
	int		h;

	i = 0;
	h = 1;
	while (i == 0 && h)
	{
		h = read(fd, str, BUFFER_SIZE);
		str[h] = '\0';
		if ((h == 0 && *finals == 0) || (h == -1))
		{
			free(finals);
			return (NULL);
		}
		if (h == 0)
			return (finals);
		finals = ft_joinfree(finals, str);
		i = ft_strichr(finals, '\n');
	}
	return (finals);
}

char	*get_next_line(int fd)
{
	static char	*finals;
	char		*rec;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!finals)
		finals = ft_calloc(1, sizeof(char));
	finals = looking_for_line(fd, finals);
	if (!finals)
		return (NULL);
	if (*finals == '\0')
		return (NULL);
	rec = line_is_here(finals);
	if (!rec)
		return (NULL);
	finals = looking_for_next_line(finals);
	return (rec);
}
