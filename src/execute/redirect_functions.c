/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:22:21 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/29 19:16:18 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	perror_exit(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	redirect_infile(int fd, t_pipex *data)
{
	if (fd < 0)
	{
		free_pipex(data);
		perror_exit("infile fd invalid");
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		close(fd);
		free_pipex(data);
		perror_exit("dup2 infile failed");
	}
	close(fd);
}

void	redirect_outfile(int fd, t_pipex *data)
{
	if (fd < 0)
	{
		free_pipex(data);
		perror_exit("outfile fd invalid");
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		close(fd);
		free_pipex(data);
		perror_exit("dup2 outfile failed");
	}
	close(fd);
}

void	redirect_pipe_in(int read_fd, t_pipex *data)
{
	if (read_fd < 0)
	{
		free_pipex(data);
		perror_exit("pipe read fd invalid");
	}
	if (dup2(read_fd, STDIN_FILENO) < 0)
	{
		close(read_fd);
		free_pipex(data);
		perror_exit("dup2 pipe read failed");
	}
	close(read_fd);
}

void	redirect_pipe_out(int write_fd, t_pipex *data)
{
	if (write_fd < 0)
	{
		free_pipex(data);
		perror_exit("pipe write fd invalid");
	}
	if (dup2(write_fd, STDOUT_FILENO) < 0)
	{
		close(write_fd);
		free_pipex(data);
		perror_exit("dup2 pipe write failed");
	}
	close(write_fd);
}
