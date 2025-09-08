/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:27:26 by nguinot-          #+#    #+#             */
/*   Updated: 2025/09/08 15:30:32 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, s++, 1);
	}
}

void	check_arg(char **args)
{
	if (!args || !args[0])
	{
		perror("erreur split ou cmd vide");
		free(args);
		exit(127);
	}
}

void	execute_cmd(char *cmd, char **envp, t_pipex *px)
{
	char	**args;
	char	*cmd_path;
	char	*msg;

	args = ft_split_cmd(cmd);
	check_arg(args);
	cmd_path = resolve_cmd(args[0], envp);
	if (!cmd_path)
	{
		msg = ft_strjoin3("pipex: ", args[0], ": command not found\n");
		if (msg)
		{
			write(2, msg, ft_strlen(msg));
			free(msg);
		}
		free_split(args);
		close_all_fds(px);
		exit(127);
	}
	execve(cmd_path, args, envp);
	ft_putstr_fd("pipex: ", 2);
	perror(args[0]);
	free_split(args);
	free(cmd_path);
	exit(1);
}
