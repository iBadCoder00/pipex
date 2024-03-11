/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:29:22 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/25 17:29:22 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*buffer_file(char *buffer, int fd)
{
	int		n_bytes;
	char	*temp_buffer;

	n_bytes = 1;
	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	while (n_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		n_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (n_bytes < 0)
		{
			free(buffer);
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[n_bytes] = 0;
		buffer = ft_strapp_g(buffer, temp_buffer);
	}
	free(temp_buffer);
	return (buffer);
}

char	*next_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!line_length(buffer))
		return (NULL);
	line = malloc(line_length(buffer) + 1);
	if (!line)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*realoc_buffer(char *buffer)
{
	int		i;
	int		start;
	char	*new_buffer;

	start = line_length(buffer);
	if (!buffer[start])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(ft_strlen(buffer) - start + 1);
	if (!new_buffer)
		return (NULL);
	i = 0;
	while (buffer[start])
		new_buffer[i++] = buffer[start++];
	new_buffer[i] = 0;
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = buffer_file(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = next_line(buffer[fd]);
	buffer[fd] = realoc_buffer(buffer[fd]);
	return (line);
}
