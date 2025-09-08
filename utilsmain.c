/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:28:24 by nguinot-          #+#    #+#             */
/*   Updated: 2025/09/08 15:30:51 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_argc(int argc, char **argv)
{
	if (argc != 5)
	{
		fprintf(stderr, "usage : %s infile \"cmd1\" \"cmd2\" outfile\n", argv[0]);
		exit (1);
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
		return (1);
	}
	return (0);
}

int	check_pid(pid_t pid, int fd[2], int infile, int outfile)
{
	if (pid == -1)
	{
		perror("fork");
		close_all(fd, infile, outfile);
		return (1);
	}
	return (0);
}

// void	check_acces_infile(char **argv)
// {
// 	if (access(argv[1], R_OK) == -1)
// 	{
// 		perror("infile access");
// 		exit(EXIT_FAILURE);
// 	}
// }

void	check_acces_infile(char **argv)
{
	if (access(argv[1], R_OK) == -1)
	{
		perror("infile access");
	}
}
