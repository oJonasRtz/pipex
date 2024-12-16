/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:20:22 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/16 14:42:45 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **env)
{
	pid_t	pid;
	pid_t	pid_parent;
	int		fd[2];
	int		exit_code;	

	if (argc != 5)
		exit(ft_printf("Error: Too few arguments.\n"));
	exit_code = 0;
	if (pipe(fd) < 0)
		exit(ft_printf("Error: Pipe failed\n"));
	pid = fork();
	if (pid < 0)
		exit(ft_printf("Error: Fork failed."));
	if (pid == 0)
		child(argv, env, fd);
	pid_parent = fork();
	if (pid_parent < 0)
		exit(ft_printf("Error: Fork failed"));
	if (pid_parent == 0)
		parent(argv, env, fd);
	close (fd[0]);
	close (fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid_parent, &exit_code, 0);
	return (exit_code);
}
