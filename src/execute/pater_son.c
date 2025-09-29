/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pater_son.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:05:50 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/29 19:13:51 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t	first_child(t_pipex *data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (ft_putstr_fd("fork: Resource not available.\n", 2), -1);
	if (pid == 0)
	{
		redirect_infile(data->infile_fd, data);
		redirect_pipe_out(data->pipe_fd[1], data);
		close(data->pipe_fd[0]);
		close(data->outfile_fd);
		execute(data->cmds, data);
	}
	return (pid);
}

static pid_t	second_child(t_pipex *data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (ft_putstr_fd("fork: Resource not available.\n", 2), -1);
	if (pid == 0)
	{
		redirect_pipe_in(data->pipe_fd[0], data);
		redirect_outfile(data->outfile_fd, data);
		close(data->pipe_fd[1]);
		close(data->infile_fd);
		execute(data->cmds->next, data);
	}
	return (pid);
}

int	pater_familias(t_pipex *data)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (pipe(data->pipe_fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid1 = first_child(data);
	pid2 = second_child(data);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	status1 = -1;
	if (pid1 > 0)
		waitpid(pid1, &status1, 0);
	status2 = -1;
	if (pid2 > 0)
		waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (1);
}
