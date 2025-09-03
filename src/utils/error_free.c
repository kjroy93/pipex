/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:14:43 by kjroy93           #+#    #+#             */
/*   Updated: 2025/09/03 21:02:31 by kmarrero         ###   ########.fr       */
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
