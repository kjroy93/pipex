/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:28:47 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/31 13:33:18 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute(t_cmd *cmd, char **envp)
{
	char	*path;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return ;
	path = define_path(cmd->argv[0], envp);
	if (!path)
	{
		perror("command not found");
		exit(1);
	}
	execve(path, cmd->argv, envp);
	perror("execve");
	free(path);
	exit(1);
}

static void	first_child(t_pipex *data, char **envp, int fd[2])
{
	pid_t	process_id;

	process_id = fork();
	if (process_id < 0)
	{
		perror("error");
		return ;
	}
	if (process_id == 0)
	{
		redirect_infile(data->infile_fd);
		redirect_pipe_out(fd[1]);
		close(fd[0]);
		execute(data->cmds, envp);
	}
}

static void	second_child(t_pipex *data, char **envp, int fd[2])
{
	pid_t	process_id;

	process_id = fork();
	if (process_id < 0)
	{
		perror("error");
		return ;
	}
	if (process_id == 0)
	{
		redirect_pipe_in(fd[0]);
		redirect_outfile(data->outfile_fd);
		close(fd[1]);
		execute(data->cmds->next, envp);
	}
}

void	pater_familias(t_pipex *data, char **envp)
{
	int		fd[2];

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
