/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:13:50 by nguinot-          #+#    #+#             */
/*   Updated: 2025/07/08 12:59:31 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	linefinished(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*readfile(int fd, char **stash)
{
	char	*buffer;
	size_t	bytesread;

	while (linefinished(*stash) != 1)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytesread = read(fd, buffer, BUFFER_SIZE);
		buffer[bytesread] = '\0';
		if (bytesread <= 0)
		{
			free(buffer);
			return (NULL);
		}
		ft_switchup(stash, &buffer);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;

	if (tchek(fd, &stash) == 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	readfile(fd, &stash);
	if (!stash)
		return (NULL);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (clean(&stash));
}
