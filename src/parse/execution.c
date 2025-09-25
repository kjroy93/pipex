/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:05:50 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/25 21:07:17 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t	first_child(t_pipex *data, char **envp, int fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork first child");
		return (-1);
	}
	if (pid == 0)
	{
		redirect_infile(data->infile_fd);
		redirect_pipe_out(fd[1]);
		close(fd[0]);
		close(data->outfile_fd);
		execute(data->cmds, data, envp);
	}
	return (pid);
}

static pid_t	second_child(t_pipex *data, char **envp, int fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork second child");
		return (-1);
	}
	if (pid == 0)
	{
		redirect_pipe_in(fd[0]);
		redirect_outfile(data->outfile_fd);
		close(fd[1]);
		close(data->infile_fd);
		execute(data->cmds->next, data, envp);
	}
	return (pid);
}

int	pater_familias(t_pipex *data, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	pid1 = first_child(data, envp, fd);
	pid2 = second_child(data, envp, fd);
	close(fd[0]);
	close(fd[1]);
	status1 = -1;
	if (pid1 > 0)
		waitpid(pid1, &status1, 0);
	status2 = -1;
	if (pid2 > 0)
		waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2) && WEXITSTATUS(status2) == 0)
		return (0);
	return (1);
}
