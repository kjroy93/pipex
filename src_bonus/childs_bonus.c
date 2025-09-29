/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:34:52 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/29 19:14:53 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child_bonus(t_pipex *data, t_cmd *cmd)
{
	redirect_infile(data->infile_fd, data);
	if (cmd->next)
	{
		redirect_pipe_out(data->pipe_fd[1], data);
		close(data->pipe_fd[0]);
	}
	else
		redirect_outfile(data->outfile_fd, data);
	close(data->outfile_fd);
}

void	mid_child_bonus(t_pipex *data, int *fd_in)
{
	redirect_pipe_in(*fd_in, data);
	redirect_pipe_out(data->pipe_fd[1], data);
	close(data->pipe_fd[0]);
	close(data->infile_fd);
	close(data->outfile_fd);
}

void	last_child_bonus(t_pipex *data, int *fd_in)
{
	redirect_pipe_in(*fd_in, data);
	redirect_outfile(data->outfile_fd, data);
	close(*fd_in);
	close(data->infile_fd);
}
