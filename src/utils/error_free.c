/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:22:12 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/22 19:22:14 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	perror_free(char *message, t_pipex *data, char *path)
{
	perror(message);
	cmd_free(&data->cmds);
	if (data->pids)
		free(data->pids);
	free(path);
	free(data);
	data = NULL;
	path = NULL;
	exit(EXIT_FAILURE);
}
