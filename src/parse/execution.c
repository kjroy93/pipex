/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:22:40 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/22 20:38:16 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute(t_cmd *cmd, t_pipex *data, char **envp)
{
	char	*path;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return ;
	path = define_path(cmd->argv[0], envp);
	if (!path)
	{
		perror(cmd->argv[0]);
		cmd_free(&data->cmds);
		free(path);
		free(data);
		exit(1);
	}
	if (execve(path, cmd->argv, envp) == -1)
		execve("/bin/bash", (char *[]){"bash", path, NULL}, envp);
	perror("execve");
	cmd_free(&data->cmds);
	free(path);
	free(data);
	exit(1);
}

static void	first_child(t_pipex *data, char **envp, int fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork first child");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		redirect_infile(data->infile_fd);
		redirect_pipe_out(fd[1]);
		close(fd[0]);
		close(fd[1]);
		execute(data->cmds, data, envp);
	}
}

static void	second_child(t_pipex *data, char **envp, int fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork second child");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		redirect_pipe_in(fd[0]);
		redirect_outfile(data->outfile_fd);
		close(fd[0]);
		close(fd[1]);
		execute(data->cmds->next, data, envp);
	}
}

void	pater_familias(t_pipex *data, char **envp)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return ;
	}
	first_child(data, envp, fd);
	second_child(data, envp, fd);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
}
