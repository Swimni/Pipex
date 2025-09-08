/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmainbonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 21:15:03 by mbuisson          #+#    #+#             */
/*   Updated: 2025/08/11 16:53:55 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	while_fork(char **envp, int argc, int **pipes, char **argv)
// {
// 	int		i;
// 	int		n_cmd;
// 	int		infile;
// 	int		outfile;
// 	int		err;
// 	pid_t	pid;

// 	n_cmd = argc - 3;
// 	err = infile_outfile(&infile, &outfile, argc, argv);
// 	if (err != 0)
// 	{
// 		close(infile);
// 		close_free_pipes(pipes, argc - 3);
// 		free(pipes);
// 		exit(EXIT_FAILURE);
// 	}
// 	i = -1;
// 	while (++i < n_cmd)
// 	{
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			if (i == 0)
// 				first_cmd(infile, pipes, i);
// 			else if (i == n_cmd -1)
// 				last_cmd(outfile, pipes, i);
// 			else
// 				middle_cmd(pipes, i);
// 			close_everything(infile, outfile, n_cmd, pipes);
// 			execute_cmd_bonus(argv[i + 2], envp);
// 		}
// 	}
// 	close_both(infile, outfile);
// }

// void	while_fork(int argc, t_exec *ex)
// {
// 	int		err;
// 	pid_t	pid;

// 	ex->n_cmd = argc - 3;
// 	err = infile_outfile(&ex->infile, &ex->outfile, argc, ex->argv);
// 	if (err != 0)
// 	{
// 		close(ex->infile);
// 		close_free_pipes(ex->pipes, argc - 3);
// 		free(ex->pipes);
// 		exit(EXIT_FAILURE);
// 	}
// 	ex->i = -1;
// 	while (++ex->i < ex->n_cmd)
// 	{
// 		pid = fork();
// 		if (pid == 0)
// 			exec_child(ex);
// 	}
// 	//close_everything(ex->infile, ex->outfile, ex->n_cmd, ex ->pipes);
// 	close_both(ex->infile, ex->outfile);
// }

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
