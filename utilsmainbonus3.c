/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmainbonus3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:10:15 by mbuisson          #+#    #+#             */
/*   Updated: 2025/08/11 16:56:10 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	infile_outfile(int *infile, int *outfile, int argc, char **argv)
{
	*infile = open(argv[1], O_RDONLY);
	if (*infile < 0)
		perror("open infile");
	*outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*outfile < 0)
	{
		perror("open outfile");
		return (1);
	}
	return (0);
}

void	close_both(int infile, int outfile)
{
	if (infile >= 0)
		close(infile);
	if (outfile >= 0)
		close(outfile);
}

void	safe_close(int fd)
{
	if (fd >= 0)
		close(fd);
}

void	close_free_pipes(int **pipes, int n_cmd)
{
	int	m;

	m = 0;
	while (m < n_cmd - 1)
	{
		close(pipes[m][0]);
		close(pipes[m][1]);
		free(pipes[m]);
		m++;
	}
}

void	close_everything(int infile, int outfile, int n_cmd, int **pipes)
{
	int	i;

	i = 0;
	close_both(infile, outfile);
	while (i < n_cmd -1)
	{
		safe_close(pipes[i][0]);
		safe_close(pipes[i][1]);
		i++;
	}
}
