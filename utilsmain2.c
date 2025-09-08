/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmain2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:13:05 by mbuisson          #+#    #+#             */
/*   Updated: 2025/08/11 16:52:00 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_pid1(t_pipex *px, char **argv, char **envp)
{
	int	devnull;

	if (px->infile >= 0)
		dup2(px->infile, STDIN_FILENO);
	else
	{
		devnull = open("/dev/null", O_RDONLY);
		dup2(devnull, STDIN_FILENO);
		close(devnull);
	}
	dup2(px->fd[1], STDOUT_FILENO);
	close(px->fd[0]);
	close(px->fd[1]);
	if (px->infile >= 0)
		close(px->infile);
	execute_cmd(argv[2], envp, px);
}

void	exec_pid2(t_pipex *px, char **argv, char **envp)
{	
	dup2(px->fd[0], STDIN_FILENO);
	dup2(px->outfile, STDOUT_FILENO);
	close(px->fd[0]);
	close(px->fd[1]);
	close(px->outfile);
	execute_cmd(argv[3], envp, px);
}

void	close_all(int fd[2], int infile, int outfile)
{
	close(fd[0]);
	close(fd[1]);
	close(infile);
	close(outfile);
}

void	wait_all(pid_t pid1, pid_t pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	close_all_fds(t_pipex *px)
{
	if (px->infile != -1)
		close(px->infile);
	if (px->outfile != -1)
		close(px->outfile);
	close(px->fd[0]);
	close(px->fd[1]);
}
