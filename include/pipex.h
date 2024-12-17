/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:20:45 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/17 12:21:44 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	pid_t	pid;
	pid_t	pid_parent;
	int		fd[2];
}	t_pipex;

//	Pipex
void	child(char **argv, char **env, t_pipex *pipex);
void	parent(char **argv, char **env, t_pipex *pipex);

//	Utils
int		close_fd(t_pipex *pipex, char *message, int exit);

#endif
