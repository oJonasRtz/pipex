/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 11:42:59 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/15 13:09:31 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	alloc_file(char **dest, char *file)
{
	int	len;
	int	i;

	len = ft_strlen(file);
	(*dest) = ft_calloc(len + 1, 1);
	i = 0;
	while (i < len)
	{
		(*dest)[i] = file[i];
		i++;
	}
	(*dest)[i] = '\0';
}

int	init_file(t_params *params, char **argv)
{
	alloc_file(&params->outfile, argv[4]);
	if (!params->outfile)
		return (0);
	return (1);
}

int	init_cmd(t_params *params, char **argv)
{
	alloc_file(&params->cmd1, argv[2]);
	alloc_file(&params->cmd2, argv[3]);
	if (!params->cmd1 || !params->cmd2)
		return (0);
	return (1);
}
