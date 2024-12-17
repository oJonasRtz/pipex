/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:20:45 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/17 11:37:02 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>

//	Pipex
void	child(char **argv, char **env, int *pipe_fd);
void	parent(char **argv, char **env, int *pipe_fd);

//	Utils
int		close_fd(int *fd, char *message);

#endif
