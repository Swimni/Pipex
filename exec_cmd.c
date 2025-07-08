/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:14:37 by nguinot-          #+#    #+#             */
/*   Updated: 2025/07/08 16:02:46 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		free_split(args);
		error_exit("Error: split");
	}
	path = find_cmd_path(args[0], envp);
	if (!path)
	{
		free_split(args);
		error_exit("Command not found");
	}
	execve(path, args, envp);
	perror("execve failed");
	free(path);
	free_split(args);
	exit(1);
}
