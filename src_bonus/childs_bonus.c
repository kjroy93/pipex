/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:34:52 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/23 20:00:52 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child_bonus(t_pipex *data, t_cmd *cmd, int fd[2])
{
	redirect_infile(data->infile_fd);
	if (cmd->next)
	{
		redirect_pipe_out(fd[1]);
		close(fd[0]);
	}
	else
		redirect_outfile(data->outfile_fd);
	close(data->outfile_fd);
}

void	mid_child_bonus(t_pipex *data, int fd[2], int *fd_in)
{
	redirect_pipe_in(*fd_in);
	redirect_pipe_out(fd[1]);
	close(fd[0]);
	close(data->infile_fd);
	close(data->outfile_fd);
}

void	last_child_bonus(t_pipex *data, int *fd_in)
{
	redirect_pipe_in(*fd_in);
	redirect_outfile(data->outfile_fd);
	close(*fd_in);
	close(data->infile_fd);
}
