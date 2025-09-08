/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:14:49 by mbuisson          #+#    #+#             */
/*   Updated: 2025/08/22 14:41:42 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	px;
	pid_t	pid1;
	pid_t	pid2;

	check_argc(argc, argv);
	check_acces_infile(argv);
	px.infile = open(argv[1], O_RDONLY);
	check_infile(px.infile);
	check_acces_outfile(argc, argv, px.infile);
	px.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	check_outfile(px.outfile, px.infile);
	if (pipe(px.fd) == -1)
		return (perror("pipe"), 1);
	pid1 = fork();
	if (pid1 == -1)
		check_pid(pid1, px.fd, px.infile, px.outfile);
	if (pid1 == 0)
		exec_pid1(&px, argv, envp);
	pid2 = fork();
	check_pid(pid2, px.fd, px.infile, px.outfile);
	if (pid2 == 0)
		exec_pid2(&px, argv, envp);
	close_all_fds(&px);
	wait_all(pid1, pid2);
	return (0);
}
