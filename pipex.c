/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:44:12 by nguinot-          #+#    #+#             */
/*   Updated: 2025/07/08 16:02:24 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_infile(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("infile");
	return (fd);
}

int	open_outfile(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		error_exit("outfile");
	return (fd);
}

void	init_pipex(t_pipex *px, char **argv, int argc, char **envp)
{
	px->infile_fd = open_infile(argv[1]);
	px->outfile_fd = open_outfile(argv[argc - 1]);
	px->cmds = argv + 2;
	px->cmd_count = argc - 3;
	px->envp = envp;
}
