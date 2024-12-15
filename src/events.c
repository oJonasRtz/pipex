/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:22:01 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/15 14:20:56 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	create(t_params *params, char **argv)
{
	if (!validate_file(params, argv))
		destroy(params, "Error: Couldn't open the files", 1);
	if (!init_file(params, argv) || !init_cmd(params, argv))
		destroy(params, "Error: Couldn't initiate the values.", 1);
	execute(params);
	return (1);
}

int	execute(t_params *params)
{
	pid_t	pid;

	if (pipe(params->pipe_fd) < 0)
		destroy(params, "Error: Pipe failed.", -1);
	pid = fork();
	if (pid < 0)
		destroy(params, "Error: fork failed.", -1);
	destroy(params, "Program successfully closed.", 0);
	return (1);
}

int	destroy(t_params *params, char *message, int exit_return)
{
	free(params->infile);
	free(params->outfile);
	free(params->cmd1);
	free(params->cmd2);
	close(params->in_fd);
	close(params->out_fd);
	close(params->pipe_fd[0]);
	close(params->pipe_fd[1]);
	set_null(params);
	if (message)
		ft_printf("%s\n", message);
	exit(exit_return);
}
