/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:27:48 by nguinot-          #+#    #+#             */
/*   Updated: 2025/09/08 15:31:54 by nguinot-         ###   ########.fr       */
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

int	main(int argc, char **argv, char **envp)
{
	t_exec	ex;
	int		l;

	check_argc(argc, argv);
	init_exec(&ex, argc, argv, envp);
	while_fork(&ex);
	free(ex.pipes);
	l = 0;
	while (l < ex.n_cmd)
	{
		wait(NULL);
		l++;
	}
	return (0);
}
