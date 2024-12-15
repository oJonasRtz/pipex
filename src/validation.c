/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:25:35 by jopereir          #+#    #+#             */
/*   Updated: 2024/12/15 14:21:36 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	validate_file(t_params *params, char **argv)
{
	params->in_fd = open(argv[1], O_RDONLY);
	params->out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (params->in_fd < 0 || params->out_fd < 0)
		return (0);
	return (1);
}
