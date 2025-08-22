/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:22:12 by kmarrero          #+#    #+#             */
/*   Updated: 2025/08/09 22:07:03 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_and_accumulate(int fd, char *chunk)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	while (!ft_strchr(chunk, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(chunk), NULL);
		buffer[bytes] = '\0';
		tmp = ft_strjoin(chunk, buffer);
		free(chunk);
		chunk = tmp;
		if (!chunk)
			return (NULL);
	}
	return (chunk);
}

static char	*extract_line(char *chunk)
{
	size_t	i;
	char	*line;

	if (!chunk || chunk[0] == '\0')
		return (NULL);
	i = 0;
	while (chunk[i] && chunk[i] != '\n')
		i++;
	if (chunk[i] == '\n')
		i++;
	line = ft_substr(chunk, 0, i);
	return (line);
}

static char	*update_chunk(char *chunk)
{
	size_t	i;
	char	*new_chunk;

	i = 0;
	while (chunk[i] && chunk[i] != '\n')
		i++;
	if (!chunk[i])
		return (free(chunk), NULL);
	new_chunk = ft_strdup(chunk + i + 1);
	free(chunk);
	return (new_chunk);
}

char	*get_next_line(int fd)
{
	static char	*chunk;
	char		*line;

	if (fd == -1)
	{
		free(chunk);
		chunk = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!chunk)
		chunk = ft_strdup("");
	if (!chunk)
		return (NULL);
	chunk = read_and_accumulate(fd, chunk);
	if (!chunk || chunk[0] == '\0')
	{
		free(chunk);
		chunk = NULL;
		return (NULL);
	}
	line = extract_line(chunk);
	chunk = update_chunk(chunk);
	return (line);
}
