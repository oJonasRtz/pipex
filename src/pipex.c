/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:53:10 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/16 14:34:17 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_cmd(char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
}

/*
	OBS: env[i] + 5 is for ignore "PATH=" before the paths
*/
static	char	*find_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*path;
	char	*temp_path;

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(path, F_OK) == 0)
		{
			free_cmd(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_cmd(paths);
	return (NULL);
}

static void	execute_process(char *argv, char **env)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], env);
	if (!path)
	{
		free_cmd(cmd);
		exit (ft_printf("Error: Path failed.\n"));
	}
	if (execve(path, cmd, env) == -1)
		exit (ft_printf("Error: Excve failed.\n"));
}

void	child(char **argv, char **env, int *pipe_fd)
{
	int		in_fd;

	in_fd = open(argv[1], O_RDONLY, 0777);
	if (in_fd < 0)
		exit (ft_printf("Error: Couldn't open infile.\n"));
	dup2(pipe_fd[1], STDOUT_FILENO);
	dup2(in_fd, STDIN_FILENO);
	close(pipe_fd[0]);
	close(in_fd);
	execute_process(argv[2], env);
}

void	parent(char **argv, char **env, int *pipe_fd)
{
	int	out_fd;

	out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out_fd < 0)
		exit (ft_printf("Error: Coundn't open the outfile.\n"));
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(pipe_fd[1]);
	close(out_fd);
	execute_process(argv[3], env);
}
