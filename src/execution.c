/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:28:47 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/31 00:22:23 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void execute(t_cmd *cmd, char **envp)
{
	char	*path;

	if (!cmd || !cmd->argv || cmd->argv[0])
		return ;
	path = define_path(cmd->argv[0], envp);
	if (!path)
	{
		perror("command not found");
		return ;
	}
	execve(path, cmd->argv, envp);
	perror("execve");
	free(path);
	exit(1);
}

void first_child(t_pipex *data, char **envp)
{
	int		fd[2];
	int		infile_fd;
	pid_t	pid1;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return ;
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		redirect_infile(data->infile_fd);
		redirect_pipe_out(fd[1]);
		close(fd[0]);
		execute(data->cmds, envp);
	}
	close(fd[0]);
	close(fd[1]);
}
