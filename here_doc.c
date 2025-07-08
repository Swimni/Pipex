/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:10:06 by nguinot-          #+#    #+#             */
/*   Updated: 2025/07/08 16:05:02 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_here_doc_input(char *limiter, int write_fd)
{
	char	*line;

	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			break ;
		if (line && ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(write_fd, line, ft_strlen(line));
		free(line);
	}
}

int	open_here_doc_outfile(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		error_exit("outfile");
	return (fd);
}

void	init_here_doc(t_pipex *px, char **argv, int argc, char **envp)
{
	int	pipe_fd[2];

	if (argc < 6)
	{
		write(2, "Usage: ./pipex here_doc LIMITER cmd1 ... cmdn outfile\n", 55);
		exit(1);
	}
	if (pipe(pipe_fd) == -1)
		error_exit("pipe");
	read_here_doc_input(argv[2], pipe_fd[1]);
	close(pipe_fd[1]);
	px->infile_fd = pipe_fd[0];
	px->outfile_fd = open_here_doc_outfile(argv[argc - 1]);
	px->cmd_count = argc -4;
	px->cmds = argv + 3;
	px->envp = envp;
}
