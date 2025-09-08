/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsmain3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguinot- <nguinot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:28:33 by nguinot-          #+#    #+#             */
/*   Updated: 2025/09/08 15:30:56 by nguinot-         ###   ########.fr       */
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
