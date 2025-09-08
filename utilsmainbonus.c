/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmainbonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:28:40 by nguinot-          #+#    #+#             */
/*   Updated: 2025/09/08 15:31:04 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	while_fork(t_exec *ex)
{
	pid_t	pid;
	int		i;

	i = 0;
	while (i < ex->n_cmd)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			close_both(ex->infile, ex->outfile);
			close_free_pipes(ex->pipes, ex->n_cmd);
			free(ex->pipes);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			ex->i = i;
			exec_child(ex);
		}
		i++;
	}
	close_both(ex->infile, ex->outfile);
	close_free_pipes(ex->pipes, ex->n_cmd);
}

void	first_cmd(int infile, int **pipes, int i)
{
	int	devnull;

	if (infile >= 0)
		dup2(infile, STDIN_FILENO);
	else
	{
		devnull = open("/dev/null", O_RDONLY);
		dup2(devnull, STDIN_FILENO);
		close(devnull);
	}
	dup2(pipes[i][1], STDOUT_FILENO);
}

void	last_cmd(int outfile, int **pipes, int i)
{
	dup2(pipes[i - 1][0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
}

void	middle_cmd(int **pipes, int i)
{
	dup2(pipes[i - 1][0], STDIN_FILENO);
	dup2(pipes[i][1], STDOUT_FILENO);
}

void	close_all_bonus(int n_cmd, int **pipes, int j)
{
	while (j < n_cmd - 1)
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
		j++;
	}
}
