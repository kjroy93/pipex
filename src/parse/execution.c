/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:58:28 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/24 20:21:06 by kmarrero         ###   ########.fr       */
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
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd->argv[0], 2);
		cmd_free(&data->cmds);
		free(path);
		free(data);
		exit(127);
	}
	execve(path, cmd->argv, envp);
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
		close(data->outfile_fd);
		execute(data->cmds, data, envp);
	}
}

static pid_t	second_child(t_pipex *data, char **envp, int fd[2])
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
		close(data->infile_fd);
		execute(data->cmds->next, data, envp);
	}
	return (pid);
}

int	pater_familias(t_pipex *data, char **envp)
{
	int		fd[2];
	pid_t	pid2;
	int		status1;
	int		status2;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}
	first_child(data, envp, fd);
	pid2 = second_child(data, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(-1, &status1, 0);
	waitpid(-1, &status2, 0);
	if ((WIFEXITED(status1) && WEXITSTATUS(status1) == 0)
		&& (WIFEXITED(status2) && WEXITSTATUS(status2) == 0))
		return (0);
	return (1);
}
