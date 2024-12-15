/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:20:22 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/15 14:20:00 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_null(t_params *params)
{
	params->infile = NULL;
	params->outfile = NULL;
	params->cmd1 = NULL;
	params->cmd2 = NULL;
	params->in_fd = 0;
	params->out_fd = 0;
	params->pipe_fd[0] = 0;
	params->pipe_fd[1] = 0;
}

int	main(int argc, char *argv[])
{
	t_params	params;

	set_null(&params);
	if (argc != 5)
		destroy(&params,
			"Error: Too few arguments.\n./pipex infile cm1 cm2 outfile", 1);
	create(&params, argv);
	return (0);
}
