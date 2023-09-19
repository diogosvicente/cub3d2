/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:42:04 by dioda-si          #+#    #+#             */
/*   Updated: 2022/12/23 03:57:05 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_linelen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0' && str[index] != '\n')
		index++;
	return (index);
}

char	*ft_remove_line_from_static(char *buffer)
{
	int		buffer_len;
	int		line_len;
	int		i;
	char	*buffer_with_n_line;

	if (buffer == NULL)
		return (NULL);
	buffer_len = 0;
	line_len = ft_linelen(buffer);
	i = 0;
	while (buffer[buffer_len] != '\0')
		buffer_len++;
	if (buffer[line_len] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	buffer_with_n_line = ft_calloc(buffer_len - line_len + 1, sizeof(char));
	if (!buffer_with_n_line)
		return (NULL);
	while (buffer[line_len] != '\0')
		buffer_with_n_line[i++] = buffer[1 + line_len++];
	free(buffer);
	return (buffer_with_n_line);
}

char	*ft_make_line(char *static_var)
{
	char	*line;
	int		line_len;
	int		i;

	i = 0;
	line_len = ft_linelen(static_var);
	line = ft_calloc(line_len + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (static_var[i] != '\0' && static_var[i] != '\n')
	{
		line[i] = static_var[i];
		i++;
	}
	if (static_var[i] != '\0' && static_var[i] != '\0')
		line[i] = '\n';
	return (line);
}

char	*ft_read_file(int fd, char *static_var)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	int		bytes_read;

	if (!static_var)
		static_var = ft_calloc(1, 1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(static_var);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(static_var, buffer);
		free(static_var);
		static_var = ft_strdup(temp);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (static_var);
}

char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_str = ft_read_file(fd, static_str);
	if (static_str == NULL)
		return (NULL);
	line = ft_make_line(static_str);
	static_str = ft_remove_line_from_static(static_str);
	return (line);
}
