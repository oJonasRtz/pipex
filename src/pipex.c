/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:53:10 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/17 14:07:26 by jopereir         ###   ########.fr       */
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

	i = 0;
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (access(path, F_OK | X_OK) == 0)
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

static void	execute_process(char *argv, char **env, t_pipex *pipex)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], env);
	if (!path)
	{
		free_cmd(cmd);
		exit(close_fd(pipex, NULL, 127));
	}
	if (execve(path, cmd, env) == -1)
	{
		free_cmd(cmd);
		exit(close_fd(pipex, NULL, 127));
	}
}

void	child(char **argv, char **env, t_pipex *pipex)
{
	int		in_fd;

	in_fd = open(argv[1], O_RDONLY, 0777);
	if (in_fd < 0)
		exit (close_fd(pipex, "Error: Couldn't open infile.", 1));
	if (dup2(pipex->fd[1], STDOUT_FILENO) < 0
		|| dup2(in_fd, STDIN_FILENO) < 0)
	{
		close(in_fd);
		exit(close_fd(pipex, NULL, 1));
	}
	close_fd(pipex, NULL, 0);
	close(in_fd);
	execute_process(argv[2], env, pipex);
}

void	parent(char **argv, char **env, t_pipex *pipex)
{
	int	out_fd;

	out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out_fd < 0)
		exit (close_fd(pipex, "Error: Coundn't open the outfile.", 1));
	if (dup2(pipex->fd[0], STDIN_FILENO) < 0
		|| dup2(out_fd, STDOUT_FILENO) < 0)
	{
		close (out_fd);
		exit(close_fd(pipex, NULL, 1));
	}
	close_fd(pipex, NULL, 0);
	close(out_fd);
	execute_process(argv[3], env, pipex);
}
