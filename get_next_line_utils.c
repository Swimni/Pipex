/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:05:29 by nguinot-          #+#    #+#             */
/*   Updated: 2025/07/08 12:59:22 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*clean(char **stash)
{
	char	*line;
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	j = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
	i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = (*stash)[j];
		j++;
	}
	line[j] = '\0';
	rest = ft_strdup(*stash + i);
	free(*stash);
	*stash = rest;
	return (line);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(ft_strlen((char *)s) + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	ft_switchup(char **stash, char **buffer)
{
	char	*tmp;

	tmp = ft_strdup(*stash);
	free(*stash);
	*stash = ft_strjoin(tmp, *buffer);
	free(tmp);
	free(*buffer);
}

int	tchek(int fd, char **stash)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(*stash);
		*stash = NULL;
		return (0);
	}
	return (1);
}
