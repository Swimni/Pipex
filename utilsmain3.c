/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmain3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuisson <mbuisson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:52:22 by mbuisson          #+#    #+#             */
/*   Updated: 2025/08/04 16:31:10 by mbuisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_acces_outfile(int argc, char **argv, int infile)
{
	if (access(argv[argc - 1], F_OK) == 0
		&& access(argv[argc - 1], W_OK) == -1)
	{
		perror("outfile access");
		close(infile);
		exit(EXIT_FAILURE);
	}
}
