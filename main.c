/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:26:17 by nguinot-          #+#    #+#             */
/*   Updated: 2025/07/08 16:06:05 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;
	int		here_doc;

	if (argc < 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		return (1);
	}
	here_doc = ft_strncmp(argv[1], "here_doc", 9) == 0;
	px.envp = envp;
	if (here_doc)
		init_here_doc(&px, argv, argc, envp);
	else
		init_pipex(&px, argv, argc, envp);
	if (px.cmd_count < 1)
		return (write(2, "No command given\n", 18), 1);
	px.pipes = malloc(sizeof(int) * 2 * (px.cmd_count - 1));
	if (!px.pipes)
		return (perror("malloc"), 1);
	create_pipe_chain(&px);
	free(px.pipes);
	return (0);
}
