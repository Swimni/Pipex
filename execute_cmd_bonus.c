/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:15:12 by mbuisson          #+#    #+#             */
/*   Updated: 2025/08/15 01:25:31 by nguinot-         ###   ########.fr       */
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

void	check_arg_bonus(char **args, t_exec *ex)
{
	if (!args || !args[0])
	{
		perror("erreur split ou cmd vide");
		free(args);
		free_pipes(ex->pipes, ex->i);
		exit(127);
	}
}

void	execute_cmd_bonus(char *cmd, t_exec *ex)
{
	char	**args;
	char	*cmd_path;
	char	*msg;

	args = ft_split_cmd(cmd);
	check_arg_bonus(args, ex);
	cmd_path = resolve_cmd(args[0], ex->envp);
	if (!cmd_path)
	{
		msg = ft_strjoin3("pipex: ", args[0], ": command not found\n");
		if (msg)
		{
			write(2, msg, ft_strlen(msg));
			free(msg);
		}
		free_split(args);
		free_child_and_exit(ex, 127);
	}
	execve(cmd_path, args, ex->envp);
	ft_putstr_fd("pipex: ", 2);
	perror(args[0]);
	free_split(args);
	free(cmd_path);
	free_child_and_exit(ex, 1);
}
