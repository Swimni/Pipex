/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmainbonus4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:28:54 by nguinot-          #+#    #+#             */
/*   Updated: 2025/09/08 15:31:12 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_exec(t_exec *ex, int argc, char **argv, char **envp)
{
	ex->n_cmd = argc - 3;
	ex->argv = argv;
	ex->envp = envp;
	ex->pipes = malloc(sizeof(int [2]) * (ex->n_cmd - 1));
	if (!ex->pipes)
		exit(1);
	while_pipe(ex->pipes, ex->n_cmd);
	check_acces_infile_bonus(argv);
	ex->infile = open(argv[1], O_RDONLY);
	if (ex->infile < 0)
		perror("infile");
	check_acces_outfile_bonus(argc, argv, ex);
	ex->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (ex->outfile < 0)
	{
		perror("outfile");
		free_exec(ex);
		exit(EXIT_FAILURE);
	}
}

void	setup_cmd(t_exec *ex)
{
	if (ex->i == 0)
		first_cmd(ex->infile, ex->pipes, ex->i);
	else if (ex->i == ex->n_cmd - 1)
		last_cmd(ex->outfile, ex->pipes, ex->i);
	else
	{
		middle_cmd(ex->pipes, ex->i);
	}
	close_everything(ex->infile, ex->outfile, ex->n_cmd, ex->pipes);
}

// void	close_unused_pipes(t_exec *ex)
// {
// 	int	j;

// 	j = 0;
// 	while (j < ex->n_cmd - 1)
// 	{
// 		if (j != ex->i - 1 && j != ex->i)
// 		{
// 			close(ex->pipes[j][0]);
// 			close(ex->pipes[j][1]);
// 		}
// 		else if (j == ex->i)
// 			close(ex->pipes[j][0]);
// 		else if (j == ex->i - 1)
// 			close(ex->pipes[j][1]);
// 		j++;
// 	}
// }

void	exec_child(t_exec *ex)
{
	setup_cmd(ex);
	close_everything(ex->infile, ex->outfile, ex->n_cmd, ex->pipes);
	execute_cmd_bonus(ex->argv[ex->i + 2], ex);
}

void	free_exec(t_exec *ex)
{
	if (ex->pipes)
	{
		close_free_pipes(ex->pipes, ex->n_cmd);
		free(ex->pipes);
	}
}

void	free_child_and_exit(t_exec *ex, int code)
{
	close_free_pipes(ex->pipes, ex->n_cmd);
	free(ex->pipes);
	exit(code);
}
