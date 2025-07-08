/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe_chain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:04:47 by nguinot-          #+#    #+#             */
/*   Updated: 2025/07/08 16:03:55 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	wait_all(int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		wait(NULL);
		i++;
	}
}

int	close_all_pipes(int pipes[][2], int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	return (0);
}

void	child_process(int i, t_pipex *px)
{
	if (i == 0)
		dup2(px->infile_fd, STDIN_FILENO);
	else
		dup2(px->pipes[i - 1][0], STDIN_FILENO);
	if (i == px->cmd_count - 1)
		dup2(px->outfile_fd, STDOUT_FILENO);
	else
		dup2(px->pipes[i][1], STDOUT_FILENO);
	close_all_pipes(px->pipes, px->cmd_count - 1);
	exec_cmd(px->cmds[i], px->envp);
	perror("exec_cmd failed");
	exit(EXIT_FAILURE);
}

void	create_pipe_chain(t_pipex *px)
{
	if (create_pipes(px->pipes, px ->cmd_count - 1) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	fork_all(px);
	close_all_pipes(px->pipes, px->cmd_count - 1);
	wait_all(px->cmd_count);
}
