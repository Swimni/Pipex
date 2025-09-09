/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:27:48 by nguinot-          #+#    #+#             */
/*   Updated: 2025/09/09 20:27:48 by nguinot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_argc(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_putstr_fd("usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putstr_fd(" infile \"cmd1\" \"cmd2\" outfile\n", 2);
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
