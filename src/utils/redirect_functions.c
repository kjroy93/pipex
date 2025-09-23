/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:22:21 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/23 19:59:24 by kmarrero         ###   ########.fr       */
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
	close(read_fd);
}

void	redirect_pipe_out(int write_fd)
{
	if (write_fd < 0 || dup2(write_fd, STDOUT_FILENO) < 0)
		perror_exit("dup2 pipe write");
	close(write_fd);
}
