/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:27:36 by nguinot-          #+#    #+#             */
/*   Updated: 2025/09/08 15:31:35 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((s1[i]) || (s2[i])) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*get_path_from_envp(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_cmd(char **path, char *cmd, int i)
{
	char	*full_cmd;
	char	*temp;

	while (path[i])
	{
		temp = ft_strjoin(path[i], "/");
		if (!temp)
			return (free_split(path), NULL);
		full_cmd = ft_strjoin(temp, cmd);
		free(temp);
		if (!full_cmd)
		{
			free_split(path);
			return (NULL);
		}
		if (access(full_cmd, X_OK) == 0)
		{
			free_split(path);
			return (full_cmd);
		}
		free(full_cmd);
		i++;
	}
	return (free_split(path), NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**path;
	char	*path_envp;
	int		i;

	path_envp = get_path_from_envp(envp);
	if (!path_envp)
		return (NULL);
	path = ft_split(path_envp, ':');
	if (!path)
		return (NULL);
	i = 0;
	return (get_cmd(path, cmd, i));
}
