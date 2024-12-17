/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:20:22 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/17 11:38:29 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	close_fd(int *fd, char *message)
{
	close(fd[0]);
	close(fd[1]);
	if (message)
		ft_printf("%s\n", message);
	return (1);
}

int	main(int argc, char *argv[], char **env)
{
	pid_t	pid;
	pid_t	pid_parent;
	int		fd[2];
	int		exit_code;	

	if (argc != 5)
		exit (ft_printf("Error: Too few arguments.\n"));
	exit_code = 0;
	if (pipe(fd) < 0)
		exit(close_fd(fd, "Error: Pipe failed"));
	pid = fork();
	if (pid < 0)
		exit(close_fd(fd, "Error: Fork failed."));
	if (pid == 0)
		child(argv, env, fd);
	pid_parent = fork();
	if (pid_parent < 0)
		exit(close_fd(fd, "Error: Fork failed"));
	if (pid_parent == 0)
		parent(argv, env, fd);
	close_fd(fd, NULL);
	waitpid(pid, NULL, 0);
	waitpid(pid_parent, &exit_code, 0);
	return (exit_code);
}
