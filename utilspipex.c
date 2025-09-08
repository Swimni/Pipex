/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilspipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:12:50 by mbuisson          #+#    #+#             */
/*   Updated: 2025/08/04 16:48:18 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipes(int **pipes, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pipes[i])
			free(pipes[i]);
		i++;
	}
	free(pipes);
}

char	**ft_split_cmd(const char *cmd)
{
	int		argc;
	char	**argv;

	argc = count_args(cmd);
	argv = malloc(sizeof(char *) * (argc + 1));
	if (!argv)
		return (NULL);
	return (split_cmd_while(cmd, argv));
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*resolve_cmd(char *cmd, char **envp)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	else
	{
		return (get_cmd_path(cmd, envp));
	}
}

char	*ft_strdup(char *s)
{
	char	*new;
	int		lens;
	int		i;

	i = 0;
	lens = ft_strlen(s);
	new = NULL;
	new = malloc(sizeof(char) * (lens + 1));
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
