/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:37:49 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/29 21:21:27 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_infile(int fd)
{
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("dup2 infile");
		exit(EXIT_FAILURE);
	}
	close (fd);
}

void	redirect_outfile(int fd)
{
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("dup2 outfile");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	redirect_pipe_in(int fd)
{
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("dup2 pipe read");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	redirect_pipe_out(int write_fd)
{
	if (dup2(write_fd, STDOUT_FILENO) < 0)
	{
		perror("dup2 pipe write");
		exit(EXIT_FAILURE);
	}
	close(write_fd);
}
