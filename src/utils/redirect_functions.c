/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:37:49 by kjroy93           #+#    #+#             */
/*   Updated: 2025/09/02 20:14:33 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_infile(int fd)
{
	if (fd < 0 || dup2(fd, STDIN_FILENO) < 0)
		perror_exit("dup2 infile");
	close (fd);
}

void	redirect_outfile(int fd)
{
	if (fd < 0 || dup2(fd, STDOUT_FILENO) < 0)
		perror_exit("dup2 outfile");
	close(fd);
}

void	redirect_pipe_in(int read_fd)
{
	if (read_fd < 0 || dup2(read_fd, STDIN_FILENO) < 0)
		perror_exit("dup2 pipe read");
}

void	redirect_pipe_out(int write_fd)
{
	if (write_fd < 0 || dup2(write_fd, STDOUT_FILENO) < 0)
		perror_exit("dup2 pipe write");
}
