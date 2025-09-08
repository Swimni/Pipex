/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmainbonus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:08:31 by mbuisson          #+#    #+#             */
/*   Updated: 2025/08/11 16:56:57 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	while_pipe(int **pipes, int n_cmd)
{
	int	k;

	k = 0;
	while (k < n_cmd -1)
	{
		pipes[k] = NULL;
		pipes[k] = malloc(sizeof(int) * 2);
		if (!pipes[k])
		{
			free_pipes(pipes, k);
			return (1);
		}
		if (pipe(pipes[k]) == -1)
		{
			perror("pipe");
			free_pipes(pipes, k);
			return (1);
		}
		k++;
	}
	return (0);
}

int	check_infile(int infile)
{
	if (infile < 0)
	{
		perror("open infile");
		return (1);
	}
	return (0);
}

int	check_outfile(int outfile, int infile)
{
	if (outfile < 0)
	{
		perror("open outfile");
		close(infile);
		exit(EXIT_FAILURE);
	}
	return (1);
}

void	check_acces_outfile_bonus(int argc, char **argv, t_exec *ex)
{
	if (access(argv[argc - 1], F_OK) == 0
		&& access(argv[argc - 1], W_OK) == -1)
	{
		perror("outfile access");
		close(ex->infile);
		free_exec(ex);
		exit(EXIT_FAILURE);
	}
}

void	check_acces_infile_bonus(char **argv)
{
	if (!argv || !argv[1])
	{
		fprintf(stderr, "infile access: invalid argument\n");
		return ;
	}
	if (access(argv[1], R_OK) == -1)
	{
		perror("infile access");
		return ;
	}
}
