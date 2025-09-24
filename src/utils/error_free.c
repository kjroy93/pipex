/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:22:12 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/24 20:21:13 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	perror_free(t_pipex *data, t_cmd *cmd, char *path)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(cmd->argv[0], 2);
	if (data)
	{
		cmd_free(&data->cmds);
		if (data->pids)
			free(data->pids);
		if (data->infile_fd > 2)
			close(data->infile_fd);
		if (data->outfile_fd > 2)
			close(data->outfile_fd);
		if (data->heredoc)
			get_next_line(-1);
		free(data);
	}
	if (path)
		free(path);
	exit(127);
}

void	close_fd_parent(t_pipex *data)
{
	close(data->infile_fd);
	close(data->outfile_fd);
}
