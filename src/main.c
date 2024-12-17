/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:20:22 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/17 14:07:12 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_fd(t_pipex *pipex, char *message, int exit)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	if (message)
		ft_printf("%s\n", message);
	return (exit);
}

int	main(int argc, char *argv[], char **env)
{
	int		exit_code;
	t_pipex	pipex;

	if (argc != 5)
		exit (ft_printf("Error: Too few arguments.\n"));
	exit_code = 0;
	if (pipe(pipex.fd) < 0)
		exit(close_fd(&pipex, NULL, 1));
	pipex.pid = fork();
	if (pipex.pid < 0)
		exit(close_fd(&pipex, NULL, 1));
	if (pipex.pid == 0)
		child(argv, env, &pipex);
	pipex.pid_parent = fork();
	if (pipex.pid_parent < 0)
		exit(close_fd(&pipex, NULL, 1));
	if (pipex.pid_parent == 0)
		parent(argv, env, &pipex);
	close_fd(&pipex, NULL, 0);
	waitpid(pipex.pid, &exit_code, 0);
	waitpid(pipex.pid_parent, &exit_code, 0);
	return (exit_code);
}
