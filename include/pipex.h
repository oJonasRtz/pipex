/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:20:45 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/15 14:18:22 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_params
{
	int		in_fd;
	int		out_fd;
	int		pipe_fd[2];

	char	*infile;
	char	*cmd1;
	char	*cmd2;
	char	*outfile;
}	t_params;

//	init values
int		init_file(t_params *params, char **argv);
void	set_null(t_params *params);
int		init_cmd(t_params *params, char **argv);

//	validation
int		validate_file(t_params *params, char **argv);

//	Events
int		create(t_params *params, char **argv);
int		execute(t_params *params);
int		destroy(t_params *params, char *message, int exit_return);

#endif
